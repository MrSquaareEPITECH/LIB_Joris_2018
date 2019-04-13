#!/usr/bin/env bash

if [[ ! -d "lib/json-c" ]]; then
    cd lib
    git clone https://github.com/json-c/json-c.git
    cd json-c
    sh autogen.sh
    ./configure
    cmake -DBUILD_SHARED_LIBS=OFF .
    make
fi