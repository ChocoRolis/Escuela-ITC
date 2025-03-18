#ifndef DYARRAY_H
#define DYARRAY_H

#include <stddef.h> 

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} dyarray;

dyarray* arr_create(size_t initial_capacity);
void arr_free(dyarray *array);
int arr_append(dyarray *array, int value);
size_t arr_size(dyarray *array);
size_t arr_capacity(dyarray *array);
int arr_get(dyarray *array, size_t index);
int arr_set(dyarray *array, size_t index, int value);

#endif // DYARRAY_H
