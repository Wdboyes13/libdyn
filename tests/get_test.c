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

#include "../dynget.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* name = getstr("Enter Name: ");
    printf("Hello, %s!\n", name);
    free(name);
    return 0;
}