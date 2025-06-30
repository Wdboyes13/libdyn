#include "dynvec.h"
#include <stdio.h>
#include <stdlib.h>

void da_init(DynArray *da){
    da->capacity = 4;
    da->size = 0;
    da->data = malloc(da->capacity * sizeof(int));
    if (!da->data){
        perror("malloc failed");
        exit(1);
    }
}

void da_push(DynArray *da, int value){
    if (da->size >= da->capacity){
        da->capacity *= 2;
        int* temp = realloc(da->data, da->capacity * sizeof(int));
        if (!temp){
            perror("realloc failed");
            free(da->data);
            exit(1);
        }
        da->data = temp;
    }
    da->data[da->size++] = value;
}

void da_free(DynArray* da){
    free(da->data);
    da->data = NULL;
    da->size = da->capacity = 0;
}

int da_get(DynArray *da, int index){
    if (index < 0 || index >= da->size){
        fprintf(stderr, "Index out of bounds %d\n", index);
        exit(1);
    }
    return da->data[index];
}

int da_remove(DynArray *da, int index){
    int retval = da_get(da, index);
    for (int i = index; i < da->size - 1; i++) {
        da->data[i] = da->data[i + 1];
    }
    da->size--;
    return retval;
}

void da_print(DynArray* da){
    for (int i = 0; i < da->size; i++){
        printf("%d ", da->data[i]);
    }
    printf("\n");
}