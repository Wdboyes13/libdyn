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

#include <stdbool.h>
#include <stdlib.h>

// === Value Types ===
struct mapkvpcc { char* key; char* value; int used; };
struct mapkvpcf { char* key; float value; int used; };
struct mapkvpci { char* key; int value; int used; };

// === Map Containers ===
struct _mapcc { struct mapkvpcc* mmap; int len; };
struct _mapcf { struct mapkvpcf* mmap; int len; };
struct _mapci { struct mapkvpci* mmap; int len; };

// === Insert ===
int insertmapcc(struct _mapcc* inmap, char* key, char* value);
int insertmapci(struct _mapci* inmap, char* key, int value);
int insertmapcf(struct _mapcf* inmap, char* key, float value);

// === Get ===
char* getmapcc(struct _mapcc inmap, char* key, bool* found);
int getmapci(struct _mapci inmap, char* key, bool* found);
float getmapcf(struct _mapcf inmap, char* key, bool* found);

// === Make ===
struct _mapcc makemapcc();
struct _mapci makemapci();
struct _mapcf makemapcf();

// === Delete ===
void delmapcc(struct _mapcc* inmap);
void delmapci(struct _mapci* inmap);
void delmapcf(struct _mapcf* inmap);

// === Macro Magic Time ===

// CREATE NEW MAP
#define makemap(type) _Generic((type)0, \
    char*: makemapcc, \
    int: makemapci, \
    float: makemapcf \
)()

// INSERT INTO MAP
#define insertmap(map, key, val) _Generic((val), \
    char*: insertmapcc, \
    int: insertmapci, \
    float: insertmapcf \
)(&(map), key, val)

// GET VALUE (with found pointer)
#define getmap(map, key, foundptr) _Generic((map)0, \
    struct _mapcc: getmapcc, \
    struct _mapci: getmapci, \
    struct _mapcf: getmapcf \
)(map, key, foundptr)

// DELETE MAP
#define delmap(map) _Generic((map), \
    struct _mapcc: delmapcc, \
    struct _mapci: delmapci, \
    struct _mapcf: delmapcf \
)(&(map))

// QUICK GET + CHECK
#define QKGETMAP(type, varname, inmap, key)             \
    bool _found_##varname = false;                      \
    type varname = getmap(inmap, key, &_found_##varname, type); \
    if (!_found_##varname) exit(1)
    
// === Typedefs ===
typedef struct _mapcc mapcc;
typedef struct _mapci mapci;
typedef struct _mapcf mapcf;