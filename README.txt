libdyn - Some stuff using Dynamic Memory Allocation

-- Parts --

dynmap - Dynamic Key->Value Maps
         Supports char* -> int
                  char* -> float
                  char* -> char*

dynget - Dynamic String Input Getting + Prompts
         Similar to pythons input()

dynvec - Dynamic Arrays
         Currently only int 


-- How to use --

Examples are in tests/

To Build you need a C Compiler, Library Archiver (`ar`), and GNU Make (`make`)

Just run `make` to compile and make the library 

Run ./install.sh [PREFIX] to install
With [PREFIX] being where you would like it installed ( Headers in [PREFIX]/include , Library in [PREFIX]/lib )
