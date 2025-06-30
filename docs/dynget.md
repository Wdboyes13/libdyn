# DynGet Docs
__DynGet is a simple way to retrieve user input with a prompt__  
DynGet uses Dynamic Memory Allocation, to resize the input buffer so there is no input limit, while staying safe.  
It is from `dynget.h`  

## Usage
Usage is very simple  
You call it like this  
`char* var = getstr("Example Prompt: ");`  
The `getstr` function returns a `char*` which in this case is assigned to a variable   
A prompt with the text `Example Prompt: ` will be shown in this case  
  
__Make sure to call `free()` when done to avoid memory leaks__   
This is because internally, it uses memory allocation (`malloc()` and `realloc()`)  
  
## Method Signature  
For DynGet `getstr` the method signature is  
`char* getstr(const char* prompt)`  