#!/bin/sh

CC="$1"

if [ -z "$CC" ]; then
    echo "Please pass CC as arg"
    exit 1
fi

make

cd tests

echo 'Testing `dynget`'
$CC get_test.c -o get_test -L.. -ldyn
echo "Test" | ./get_test || exit 1
rm get_test

echo 'Testing `dynmap`'
$CC map_test.c -o map_test -L.. -ldyn
./map_test || exit 1
rm map_test

echo 'Testing `dynvec`'
$CC vec_test.c -o vec_test -L.. -ldyn
./vec_test || exit 1
rm vec_test

echo "Tests Succeeded"

cd ..
make clean

exit 0