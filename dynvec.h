/*
A C Library for tools using Dynamic Memory Allocation
Copyright (C) 2025  Wdboyes13

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

typedef struct {
    int* data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray* da);

void da_push(DynArray* da, int value);
int da_get(DynArray* da, int index);
void da_print(DynArray* da);

int da_remove(DynArray *da, int index);
void da_free(DynArray* da);

#define DECLDynArray(name) \
        DynArray* name = malloc(sizeof(DynArray*)); \
        da_init(name)