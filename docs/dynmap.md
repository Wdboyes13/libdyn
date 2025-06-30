# DynMap Docs  
__DynMap is for easily making Key->Value Map__  
The goal was to make it as easy as possible to use  
To do that I used C11 _Generic and Macros A LOT

## Supported Types  
- Key: `char*` Value: `int`  
- Key: `char*` Value: `char*`  
- Key: `char*` Value: `float`  
  
## Usage  
This is split into parts for each function  
  
### `QKINITMAP_` Functions  
These macros declare a `Map` of the correct type they are  
- `QKINITMAP_CHAR` - `char*` -> `char*`  
- `QKINITMAP_INT` - `char*` -> `int`  
- `QKINITMAP_FLOAT` - `char*` -> `float`  
Each one takes the parameter `name` which will be the name of the Map  
>Example usage (`char*` -> `int`)  
>`QKINITMAP_INT(mymap);` This declares a `char*` -> `int` map named `mymap`  

### `insertmap(map, key, val)` Insert a Key->Value Pair  
This macro assigns `val` to `key` in `map`  
>Example Usage  
>`insertmap(mymap, "Example", 12);` This assigns the value `12` to `"Example` in  
>the `char*` -> `int` map `mymap`  

### `QKGETMAP(type, varname, inmap, key)` Retrieve a value and assign it to a variable  
This macro gets `key` from `inmap` and assigns it to `varname` of type `type`  
If the value could not be found, it prints an error  
>Example Usage  
>`QKGETMAP(int, val, mymap, "Example");` This searches for `"Example"` in `mymap`  
>and assigns its value to an `int` named `val`  

### `delmap(map)` Delete & Free a map   
This macro deletes & frees `map`  
>Example Usage  
>`delmap(mymap);` This deletes `mymap` and frees/deallocates memory used by it  