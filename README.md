# libdyn - Some stuff using Dynamic Memory Allocation
## This Library is licensed under GPLv3 see the bottom for more info, or [LICENSE](/LICENSE)

## Library Parts
- DynVec - Dynamic `int` array  
- DynMap - Key->Value Maps  
- DynGet - Dynamic buffer input  

## How to build and use
__We are currently testing how making shared libraries an option would go__  

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

## License
  
A C Library for tools using Dynamic Memory Allocation  
Copyright (C) 2025  Wdboyes13    

This program is free software: you can redistribute it and/or modify  
it under the terms of the GNU General Public License as published by  
the Free Software Foundation, either version 3 of the License, or  
(at your option) any later version.  
  
This program is distributed in the hope that it will be useful,  
but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
GNU General Public License for more details.  
  
You should have received a copy of the GNU General Public License  
along with this program.  If not, see <https://www.gnu.org/licenses/>.  
