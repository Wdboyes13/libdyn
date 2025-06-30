#!/bin/sh
set -euo pipefail

./makelibs.sh

makerel() {
    PLATFORM=$1
    mkdir -p $PLATFORM/dynmap
    echo "Copying Headers for $PLATFORM"
    cp *.h $PLATFORM/
    cp dynmap/*.h $PLATFORM/dynmap/
    echo "Copying Library for $PLATFORM"
    cp release/libdyn-$PLATFORM.a $PLATFORM/libdyn.a  
    echo "Copying Other Stuff"
    cp install.sh $PLATFORM/
    cp -r docs $PLATFORM/
    cp LICENSE $PLATFORM/
    cp README.md $PLATFORM/
    echo "Creating Zipfile"
    zip -r -9 $PLATFORM-dynlib.zip $PLATFORM/
    rm -rf $PLATFORM/
    mv $PLATFORM-dynlib.zip release/zipz/
}

makerel linux64
makerel linuxarm
makerel mac64
makerel macarm
makerel win64