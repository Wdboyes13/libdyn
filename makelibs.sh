#!/bin/sh

mkdir -p release/zipz


echo "Making x86_64 macOS Library"
echo
make CC=clang CFLAGS="-arch x86_64" OUTS=libdyn.dylib SOFLAG=-dynamiclib
mv "./libdyn.a" "./libdyn-mac64.a"
mv "./libdyn.dylib" "./libdyn-mac64.dylib"
echo
file dynvec.o
make clean

echo
echo "Making AArch64 macOS Library"
echo
make CC=clang OUTS=libdyn.dylib SOFLAG=-dynamiclib
mv "./libdyn.dylib" "./libdyn-macarm.dylib"
echo
file dynvec.o
make clean

echo
echo "Making AArch64 Linux Library"
echo
make CC=aarch64-unknown-linux-gnu-gcc AR=aarch64-unknown-linux-gnu-ar
mv "./libdyn.a" "./libdyn-linuxarm.a"
mv "./libdyn.so" "./libdyn-linuxarm.so"
echo
file dynvec.o
make clean

echo
echo "Making x86_64 Linux Library"
echo
make CC=x86_64-unknown-linux-gnu-gcc AR=x86_64-unknown-linux-gnu-ar
mv "./libdyn.a" "./libdyn-linux64.a"
mv "./libdyn.so" "./libdyn-linux64.so"
echo
file dynvec.o
make clean

echo
echo "Making x86_64 Windows Library"
echo
make CC=x86_64-w64-mingw32-gcc AR=x86_64-w64-mingw32-ar DOSHARED=N
mv "./libdyn.a" "./libdyn-win64.a"
echo
file dynvec.o
make clean

mv *.a release/
mv *.so release/
mv *.dylib release/