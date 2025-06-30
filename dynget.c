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

#include <stdio.h>
#include <stdlib.h>

char* getstr(const char* prompt){
    printf("%s", prompt);
    int bufsize = 32;
    int len = 0;
    char *str = malloc(bufsize);
    if (!str) return NULL;

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF){
        str[len++] = ch;

        if (len >= bufsize){
            bufsize *= 2;
            char *newstr = realloc(str, bufsize);
            if (!newstr){
                free(str);
                return NULL;
            }
            str = newstr;
        }
    }
    str[len] = '\0';
    return str;
}