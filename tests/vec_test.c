#include "../dynvec.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(){
    DECLDynArray(arr);
    da_push(arr, 10);
    int val = da_get(arr, 0);
    printf("Expected 10 -> Got %d\n", val);
    assert(val == 10);
    int val2 = da_remove(arr, 0);
    printf("Expected 10 -> Got %d\n", val2);
    assert(val2 == 10);
    da_free(arr);
    return 0;
}