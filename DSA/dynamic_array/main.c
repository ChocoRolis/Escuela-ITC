#include <stdio.h>
#include "dyarray.h"

int main() {
    dyarray *array = arr_create(2);

    if (!array) {
        fprintf(stderr, "Failed to create dynamic array\n");
        return 1;
    }

    arr_append(array, 10);
    arr_append(array, 20);
    arr_append(array, 30);

    printf("Array size: %zu\n", arr_size(array));
    printf("Array capacity: %zu\n", arr_capacity(array));

    for (size_t i = 0; i < arr_size(array); ++i) {
        printf("Element at index %zu: %d\n", i, arr_get(array, i));
    }

    arr_set(array, 1, 50);

    printf("After setting index 1 to 50:\n");
    for (size_t i = 0; i < arr_size(array); ++i) {
        printf("Element at index %zu: %d\n", i, arr_get(array, i));
    }

    arr_free(array);

    return 0;
}
