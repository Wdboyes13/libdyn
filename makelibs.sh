#!/bin/sh

mkdir -p release/zipz


echo "Making x86_64 macOS Library"
echo
make CC=clang CFLAGS="-arch x86_64"
mv "./libdyn.a" "./libdyn-mac64.a"
echo
file dynvec.o
make clean

echo
echo "Making AArch64 macOS Library"
echo
make CC=clang  
mv "./libdyn.a" "./libdyn-macarm.a"
echo
file dynvec.o
make clean

echo
echo "Making AArch64 Linux Library"
echo
make CC=aarch64-unknown-linux-gnu-gcc AR=aarch64-unknown-linux-gnu-ar
mv "./libdyn.a" "./libdyn-linuxarm.a"
echo
file dynvec.o
make clean

echo
echo "Making x86_64 Linux Library"
echo
make CC=x86_64-unknown-linux-gnu-gcc AR=x86_64-unknown-linux-gnu-ar
mv "./libdyn.a" "./libdyn-linux64.a"
echo
file dynvec.o
make clean

echo
echo "Making x86_64 Windows Library"
echo
make CC=x86_64-w64-mingw32-gcc AR=x86_64-w64-mingw32-ar
mv "./libdyn.a" "./libdyn-win64.a"
echo
file dynvec.o
make clean

mv *.a release/