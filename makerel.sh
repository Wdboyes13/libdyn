#!/bin/sh
set -euo pipefail

./makelibs.sh

makerelso() {
    PLATFORM=$1
    SOEXT=$2
    mkdir -p "$PLATFORM-dynlib/dynmap"
    echo "Copying Headers for $PLATFORM"
    cp *.h "$PLATFORM-dynlib/"
    cp dynmap/*.h "$PLATFORM-dynlib/dynmap/"
    echo "Copying Library for $PLATFORM"
    cp "release/libdyn-$PLATFORM.a" "$PLATFORM-dynlib/libdyn.a"
    cp "release/libdyn-$PLATFORM.$SOEXT" "$PLATFORM-dynlib/libdyn.$SOEXT"
    echo "Copying Other Stuff"
    cp install.sh "$PLATFORM-dynlib/"
    cp -r docs "$PLATFORM-dynlib/"
    cp LICENSE "$PLATFORM-dynlib/"
    cp README.md "$PLATFORM-dynlib/"
    echo "Creating Zipfile"
    zip -r -9 "$PLATFORM-dynlib.zip" "$PLATFORM-dynlib/"
    rm -rf "$PLATFORM-dynlib/"
    gpg --output "$PLATFORM-dynlib.zip.sig" --detach-sign "$PLATFORM-dynlib.zip"
    mv "$PLATFORM-dynlib.zip" "$PLATFORM-dynlib.zip.sig" "release/zipz/"
}

makerela() {
    PLATFORM=$1
    SOEXT=$2
    mkdir -p "$PLATFORM-dynlib/dynmap"
    echo "Copying Headers for $PLATFORM"
    cp *.h "$PLATFORM-dynlib/"
    cp dynmap/*.h "$PLATFORM-dynlib/dynmap/"
    echo "Copying Library for $PLATFORM"
    cp "release/libdyn-$PLATFORM.a" "$PLATFORM-dynlib/libdyn.a"
    echo "Copying Other Stuff"
    cp install.sh "$PLATFORM-dynlib/"
    cp -r docs "$PLATFORM-dynlib/"
    cp LICENSE "$PLATFORM-dynlib/"
    cp README.md "$PLATFORM-dynlib/"
    echo "Creating Zipfile"
    zip -r -9 "$PLATFORM-dynlib.zip" "$PLATFORM-dynlib/"
    rm -rf "$PLATFORM-dynlib/"
    gpg --output "$PLATFORM-dynlib.zip.sig" --detach-sign "$PLATFORM-dynlib.zip"
    mv "$PLATFORM-dynlib.zip" "$PLATFORM-dynlib.zip.sig" "release/zipz/"
}

makerelso linux64 so
makerelso linuxarm so
makerelso mac64 dylib
makerelso macarm dylib
makerela win64 