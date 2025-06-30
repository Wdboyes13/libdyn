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

#include "../dynmap/dynmap.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int testci(){
    struct _mapci mymap = makemap(int);
    for (int i = 0; i < 15; i++){
        char buf[10];
        snprintf(buf, sizeof(buf), "Test %d", i);
        insertmap(mymap, buf, i);
    }
    for (int i = 0; i < 15; i++){
        char buf[10];
        snprintf(buf, sizeof(buf), "Test %d", i);
        QKGETMAP(int, val, mymap, buf);
        printf("Expecting %d -> Got %d\n", i, val);
        assert(val == i);
    }
    delmap(mymap);
    return 0;
}

int testcc(){
    struct _mapcc mymap = makemap(char*);
    for (int i = 0; i < 15; i++){
        char buf[10];
        snprintf(buf, sizeof(buf), "Test %d", i);
        insertmap(mymap, buf, buf);
    }
    for (int i = 0; i < 15; i++){
        char buf[10];
        snprintf(buf, sizeof(buf), "Test %d", i);
        QKGETMAP(char*, val, mymap, buf);
        printf("Expecting %s -> Got %s\n", buf, val);
        assert(strcmp(val, buf) == 0);
    }
    delmap(mymap);
    return 0;
}

int testcf(){
    struct _mapcf mymap = makemap(float);
    for (int i = 0; i < 15; i++){
        float val = (float)i;
        char buf[20];
        snprintf(buf, sizeof(buf), "Test %.2f", val);
        insertmapcf(&mymap, buf, val);
    }
    for (int i = 0; i < 15; i++){
        float val = (float)i;
        char buf[20];
        snprintf(buf, sizeof(buf), "Test %.2f", val);
        QKGETMAP(float, fval, mymap, buf);
        printf("Expecting %.2f -> Got %.2f\n", val, fval);
        assert(fval == val);
    }
    delmap(mymap);
    return 0;
}

int main(){
    if (testci() == 0) printf("String->Integer Works\n");
    if (testcc() == 0) printf("String->String Works\n");
    if (testcf() == 0) printf("String->Float Works\n");
}