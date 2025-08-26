#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>

struct string {
    char *ptr;
    size_t len;
};

// Callback function to capture HTTP response
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t real_size = size * nmemb;
    struct string *s = (struct string *)userp;
    s->ptr = realloc(s->ptr, s->len + real_size + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        return 0;
    }
    memcpy(&(s->ptr[s->len]), contents, real_size);
    s->len += real_size;
    s->ptr[s->len] = '\0';
    return real_size;
}

// Read entire file into a string
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(length + 1);
    if (!buffer) {
        fclose(file);
        perror("Failed to allocate memory");
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);
    return buffer;
}

// Join JSON array elements into a comma-separated string
char *join_json_array(json_t *array) {
    if (!json_is_array(array)) return NULL;
    size_t len = json_array_size(array);
    if (len == 0) return strdup("");
    char *result = NULL;
    size_t total_len = 0;
    for (size_t i = 0; i < len; i++) {
        const char *s = json_string_value(json_array_get(array, i));
        if (!s) {
            free(result);
            return NULL;
        }
        total_len += strlen(s) + (i == 0 ? 0 : 2);
    }
    result = malloc(total_len + 1);
    if (!result) return NULL;
    result[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        const char *s = json_string_value(json_array_get(array, i));
        if (i == 0) {
            strcpy(result, s);
        } else {
            strcat(result, ", ");
            strcat(result, s);
        }
    }
    return result;
}

// Process a single file and write results to output
void process_file(const char *filename, const char *api_key, FILE *output) {
    char *text = read_file(filename);
    if (!text) {
        fprintf(stderr, "Error reading file %s\n", filename);
        return;
    }

    // Construct the prompt
    char prompt_template[] = "Extract the following entities from the text enclosed in triple backticks: dates, person names, and locations. Format the response as a JSON object with keys 'dates', 'names', 'locations', each being an array of strings. Text: ```%s```";
    char *prompt = malloc(strlen(prompt_template) + strlen(text) + 1);
    if (!prompt) {
        perror("malloc failed");
        free(text);
        return;
    }
    sprintf(prompt, prompt_template, text);
    free(text);

    // Build the JSON request
    json_t *request = json_object();
    json_t *contents = json_array();
    json_t *content = json_object();
    json_t *parts = json_array();
    json_t *part = json_object();
    json_object_set_new(part, "text", json_string(prompt));
    free(prompt);
    json_array_append(parts, part);
    json_object_set_new(content, "parts", parts);
    json_array_append(contents, content);
    json_object_set_new(request, "contents", contents);

    // Serialize the JSON request
    char *request_data = json_dumps(request, JSON_COMPACT);
    json_decref(request);

    // Set up libcurl
    CURL *curl = curl_easy_init();
    struct string response = {0};
    if (curl) {
        char url[256];
        snprintf(url, sizeof(url), "https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=%s", api_key);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    free(request_data);

    // Parse the API response
    if (response.ptr) {
        json_error_t error;
        json_t *root = json_loads(response.ptr, 0, &error);
        free(response.ptr);
        if (!root) {
            fprintf(stderr, "JSON parse error: %s\n", error.text);
            return;
        }

        json_t *candidates = json_object_get(root, "candidates");
        if (!json_is_array(candidates) {
            fprintf(stderr, "No candidates in response\n");
            json_decref(root);
            return;
        }

        json_t *first_candidate = json_array_get(candidates, 0);
        if (!first_candidate) {
            fprintf(stderr, "No candidate found\n");
            json_decref(root);
            return;
        }

        json_t *content = json_object_get(first_candidate, "content");
        json_t *parts = json_object_get(content, "parts");
        json_t *first_part = json_array_get(parts, 0);
        json_t *text = json_object_get(first_part, "text");
        const char *entities_str = json_string_value(text);
        if (!entities_str) {
            fprintf(stderr, "No text in response\n");
            json_decref(root);
            return;
        }

        // Parse the entities JSON
        json_t *entities = json_loads(entities_str, 0, &error);
        if (!entities) {
            fprintf(stderr, "Entities JSON parse error: %s\n", error.text);
            json_decref(root);
            return;
        }

        json_t *dates = json_object_get(entities, "dates");
        json_t *names = json_object_get(entities, "names");
        json_t *locations = json_object_get(entities, "locations");

        char *dates_str = join_json_array(dates);
        char *names_str = join_json_array(names);
        char *locations_str = join_json_array(locations);

        fprintf(output, "File: %s\n", filename);
        fprintf(output, "Dates: %s\n", dates_str ? dates_str : "None found");
        fprintf(output, "Names: %s\n", names_str ? names_str : "None found");
        fprintf(output, "Locations: %s\n\n", locations_str ? locations_str : "None found");

        free(dates_str);
        free(names_str);
        free(locations_str);
        json_decref(entities);
        json_decref(root);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <api_key> <output_file> <input_file1> [input_file2 ...]\n", argv[0]);
        return 1;
    }

    const char *api_key = argv[1];
    const char *output_filename = argv[2];

    FILE *output = fopen(output_filename, "w");
    if (!output) {
        perror("Failed to open output file");
        return 1;
    }

    for (int i = 3; i < argc; i++) {
        process_file(argv[i], api_key, output);
    }

    fclose(output);
    return 0;
}
