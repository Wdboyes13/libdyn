#pragma once

typedef struct {
    int* data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray* da);
void da_push(DynArray* da, int value);
void da_free(DynArray* da);
int da_get(DynArray* da, int index);
void da_print(DynArray* da);
int da_remove(DynArray *da, int index);