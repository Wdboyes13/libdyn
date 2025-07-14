#include "../dynget.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* name = getstr("Enter Name: ");
    printf("Hello, %s!\n", name);
    free(name);
    return 0;
}