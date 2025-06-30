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