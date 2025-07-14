# libdyn - Some stuff using Dynamic Memory Allocation
## This Library is licensed under The ZLib License see [LICENSE](/LICENSE)  

## Library Parts
- DynVec - Dynamic `int` array  
- DynMap - Key->Value Maps  
- DynGet - Dynamic buffer input  

## How to build and use 
__Shared libraries will not be available for windows__  

Docs are  
- DynVec Docs are at [docs/dynvec.md](/docs/dynvec.md)  
- DynMap Docs are at [docs/dynmap.md](/docs/dynmap.md)  
- DynGet Docs are at [docs/dynget.md](/docs/dynget.md)  
  
Pre-compiled releases are available.  
  
To verify a download, get the matching `.sig` file  
Get the public key to verify at [willdev2025.asc](/willdev2025.asc) and import it with `gpg --import willdev2025.asc`  
and use `gpg --verify <filaname>.zip.sig <filename>.zip` with `<filename>` being whatever filename you downloaded  
Like macarm-dynlib or win64-dynlib  
   
To Build you need a C Compiler, Library Archiver (`ar`), and GNU Make (`make`)  

Just run `make` to compile and make the library   

Run `./install.sh [PREFIX]` to install  
With `[PREFIX]` being where you would like it installed (Headers in `[PREFIX]/include`, Library in `[PREFIX]/lib`)  
