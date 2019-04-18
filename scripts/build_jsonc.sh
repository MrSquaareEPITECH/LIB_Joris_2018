#!/usr/bin/env bash

if [[ ! -d "lib/jsonc" ]]; then
    cd lib
    wget https://github.com/json-c/json-c/archive/json-c-0.13.1-20180305.zip
    unzip *.zip
    rm *.zip
    mv json-c-* jsonc
    cd jsonc
    sh autogen.sh
    ./configure
    cmake .
    make
fi