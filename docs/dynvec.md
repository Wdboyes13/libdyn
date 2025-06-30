# DynVec Docs  
__DynVec is an `int` array that gets automatically resized__  
It is from `dynvec.h`  

## Usage
This section consists of 7 parts, 1 for each function, they are in the order of which you would normally call them  

### `DECLDynArray(name)` Allocate the initial array  
This `DECLDynArray(name)` macro automatically expands to all the setup needed   
for the `DynArray` type. This is the first thing you call  
>Example Usage   
>`DECLDynArray(arr);`  This declares and allocates a `DynArray` named `arr` as well as  
>  calls `da_init` to finish setup  

### `da_push(DynArray* da, int value)` Push a value into the array  
The `da_push` function pushes a value into a `DynArray`  
>Example Usage  
>`da_push(arr, 10);` This pushes the number `10` into the first available slot in the  
>`DynArray` named `arr`  
  
### `da_get(DynArray* da, int index)` Get a value from an array  
The `da_get` function returns the value at the specified index of a `DynArray`  
>Example Usage  
>`int val = da_get(arr, 0);` This gets the value at index `0` of the `DynArray` named `arr`  
>and assigned it to the integer named `val`  

### `da_print(DynArray* da);` Print all values in a `DynArray`  
The `da_print` function loops through a `DynArray` and prints each value stored  
>Example Usage  
>`da_print(arr);` This prints all values in the `DynArray` named `arr`  

### `da_remove(DynArray *da, int index)` Remove a value from a `DynArray`  
The `da_remove` function removes the specified index, and shifts all other values down  
>Example Usage  
>`da_remove(arr, 0)` This removes the index of `0` int eh `DynArray` named `arr`  
>and shifts other values down  

### `da_free(DynArray* da)` Free a `DynArray` once it is done being used  
The `da_free` function frees all allocations made by `DECLDynArray` as well  
as frees anything else allocated  
>Example Usage  
>`da_free(arr)` This completely frees the `DynArray` named `arr`  

## A full usage of `DynArray`  
```c
int main(){
    DECLDynArray(arr);
    da_push(arr, 10);
    int val = da_get(arr, 0);
    printf("Expected 10 -> Got %d\n", val);
    assert(val == 10);
    da_print(arr);
    int val2 = da_remove(arr, 0);
    printf("Expected 10 -> Got %d\n", val2);
    assert(val2 == 10);
    da_free(arr);
    return 0;
}
```  
## Method return types  
`da_init` `da_push` `da_print` `da_free` Are all `void` functions, they do not return anything   
`da_get` Returns an `int` from the specified index   
`da_remove` Returns the value that was previously stored at the removed index  