#!/usr/bin/env bash

if [[ ! -d "lib/json-c" ]]; then
    cd lib/jsonc
    sh autogen.sh
    ./configure
    cmake .
    make
fi