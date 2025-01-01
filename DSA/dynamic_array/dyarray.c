#include <stdio.h>
#include <stdlib.h>
#include "dyarray.h"

// Create a new dynamic array with a given initial capacity
dyarray* arr_create(size_t initial_capacity) {
    dyarray *array = (dyarray*)malloc(sizeof(dyarray));
    if (!array) {
        return NULL;
    }
    array->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!array->data) {
        free(array);
        return NULL;
    }
    array->size = initial_capacity;
    array->capacity = initial_capacity;
    return array;
}

// Destroy the dynamic array and free memory
void arr_free(dyarray *array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

// Append a value to the dynamic array, resizing if necessary
int arr_append(dyarray *array, int value) {
    if (array->size == array->capacity) {
        size_t new_capacity = array->capacity * 2;
        int *new_data = (int*)realloc(array->data, new_capacity * sizeof(int));
        if (!new_data) {
            return -1; // Memory allocation failed
        }
        array->data = new_data;
        array->capacity = new_capacity;
    }
    array->data[array->size++] = value;
    return 0;
}

// Get the current size of the dynamic array
size_t arr_size(dyarray *array) {
    return array->size;
}

// Get the current capacity of the dynamic array
size_t arr_capacity(dyarray *array) {
    return array->capacity;
}

// Get the value at a specific index in the dynamic array
int arr_get(dyarray *array, size_t index) {
    if (index >= array->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return array->data[index];
}

// Set the value at a specific index in the dynamic array
int arr_set(dyarray *array, size_t index, int value) {
    if (index >= array->size) {
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
    array->data[index] = value;
    return 0;
}
