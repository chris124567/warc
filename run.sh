#!/bin/sh
set -eux

clang-format -i -style="{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}" src/* tests/*
make -j5 clean
make -j5 main # test
./build/main
# ./build/test