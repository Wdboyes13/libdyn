#include "../dynget.h"
#include <stdio.h>

int main(){
    char* name = getstr("Enter Name: ");
    printf("Hello, %s!\n", name);
    return 0;
}