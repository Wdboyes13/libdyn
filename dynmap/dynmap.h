#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

// INSERT INTO MAP
#define insertmap(map, key, val) _Generic((val), \
    char*: insertmapcc, \
    int: insertmapci, \
    float: insertmapcf \
)(&(map), key, val)

// GET VALUE (with found pointer)
#define getmap(map, key, foundptr) _Generic((map), \
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
    type varname = getmap(inmap, key, &_found_##varname); \
    if (!_found_##varname) fprintf(stderr, "Could not find value for key %s in Map", key)

// QUICK MAP CREATE
#define QKINITMAP_CHAR(name) struct _mapcc name = makemapcc()
#define QKINITMAP_INT(name)  struct _mapci name = makemapci()
#define QKINITMAP_FLOAT(name) struct _mapcf name = makemapcf()