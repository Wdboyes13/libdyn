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

#include "../dynvec.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(){
    DECLDynArray(arr);
    da_push(arr, 10);
    int val = da_get(arr, 0);
    printf("Expected 10 -> Got %d\n", val);
    assert(val == 10);
    int val2 = da_remove(arr, 0);
    printf("Expected 10 -> Got %d\n", val2);
    assert(val2 == 10);
    da_free(arr);
    return 0;
}