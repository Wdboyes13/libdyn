#!/bin/bash

PREFIX=$1

if [ -z "$PREFIX" ]; then 
    echo "Missing Arg"
    echo "Usage: $0 [PREFIX]"
    exit 1
fi

if [ ! -f "./libdyn.a" ]; then 
    echo 'Please run `make` first'
    exit 1
fi

mkdir -p "$PREFIX/include" "$PREFIX/lib" "$PREFIX/lib/pkgconfig"

for Header in "./dynget.h" "./dynmap/dynmap.h" "./dynvec.h"; do
    echo "Copying $Header to $PREFIX/include/"
    cp "$Header" "$PREFIX/include/"
done

echo "Copying ./libdyn.a to $PREFIX/lib/"
cp "./libdyn.a" "$PREFIX/lib/"

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Copying ./libdyn.so to $PREFIX/lib/"
    cp "./libdyn.so" "$PREFIX/lib/"
fi

if [[ "$OSTYPE" == "darwin"* ]]; then
   echo "Copying ./libdyn.dylib to $PREFIX/lib/"
    cp "./libdyn.dylib" "$PREFIX/lib/"
fi

echo "Making PKG-CONFIG File"
cat > dynlib.pc <<EOF
prefix=$PREFIX
exec_prefix=\${prefix}
libdir=\${exec_prefix}/lib
includedir=\${prefix}/include

Name: dynlib
Description: A C dynamic memory toolset (DynMap, DynVec, DynGet)
Version: 1.0.0
Libs: -L\${libdir} -ldyn
Cflags: -I\${includedir}
EOF

mv "dynlib.pc" "$PREFIX/lib/pkgconfig"
