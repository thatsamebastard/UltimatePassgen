#!/bin/sh
sudo apt-get install clang
g++ ./src/main.cpp ./src/passgen.cpp ./src/passgen.h -o ~/.local/bin/passgen