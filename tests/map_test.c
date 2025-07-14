#include "../dynmap/dynmap.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int testci(){
    QKINITMAP_INT(mymap);
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
    QKINITMAP_CHAR(mymap);
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
    QKINITMAP_FLOAT(mymap);
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