#!/bin/sh

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

mkdir -p "$PREFIX/include" "$PREFIX/lib"

for Header in "./dynget.h" "./dynmap/dynmap.h" "./dynvec.h"; do
    echo "Copying $Header to $PREFIX/include/"
    cp $Header "$PREFIX/include/"
done

echo "Copying ./libdyn.a to $PREFIX/lib/"
cp "./libdyn.a" "$PREFIX/lib/"