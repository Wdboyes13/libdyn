#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynmap.h"

int insertmapcc(struct _mapcc* inmap, char* key, char* value){
    for (int i = 0; i < inmap->len; i++){
        if (inmap->mmap[i].used == 0){
            inmap->mmap[i].value = strdup(value);
            if (!inmap->mmap[i].value) {
                perror("strdup failed\n");
                exit(1);
            }
            inmap->mmap[i].key = strdup(key);
            if (!inmap->mmap[i].key) {
                perror("strdup failed\n");
                exit(1);
            }
            inmap->mmap[i].used = 1;
            return 0;
        }
    }
    int oldlen = inmap->len;
    int newlen = oldlen * 2;
    struct mapkvpcc *new_mmap = realloc(inmap->mmap, newlen * sizeof(struct mapkvpcc));
    if (!new_mmap) {
        perror("realloc failed\n");
        exit(1);
        return 1;
    }

    for (int i = oldlen; i < newlen; i++) {
        new_mmap[i].used = 0;
        new_mmap[i].key = NULL;
        new_mmap[i].value = 0;
    }

    inmap->mmap = new_mmap;
    inmap->len = newlen;

    inmap->mmap[oldlen].value = strdup(value);
    if (!inmap->mmap[oldlen].value) {
        perror("strdup failed\n");
        exit(1);
    }
    inmap->mmap[oldlen].key = strdup(key);
    if (!inmap->mmap[oldlen].key) {
        perror("strdup failed\n");
        exit(1);
    }
    inmap->mmap[oldlen].used = 1;
    return 0;
}

char* getmapcc(struct _mapcc inmap, char* key, bool* found){
    for (int i = 0; i < inmap.len; i++){
        if (strcmp(inmap.mmap[i].key, key) == 0){
            *found = true;
            return inmap.mmap[i].value;
        }
    }
    *found = false;
    return NULL;
}

struct _mapcc makemapcc(){
    struct _mapcc retmap;
    retmap.len = 10;
    retmap.mmap = calloc(retmap.len, sizeof(struct mapkvpcc));
    if (!retmap.mmap){
        perror("calloc failed\n");
        exit(1);
    }
    return retmap;
}

void delmapcc(struct _mapcc* inmap){
    if (inmap->mmap != NULL) {
        for (int i = 0; i < inmap->len; i++) {
            if (inmap->mmap[i].used && inmap->mmap[i].key != NULL) {
                free(inmap->mmap[i].key);
                free(inmap->mmap[i].value);
            }
        }
        free(inmap->mmap);
        inmap->mmap = NULL;
    }
    inmap->len = 0;
}