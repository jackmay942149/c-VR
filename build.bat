@echo off
set SRC_FILES=src/main.c src/color.c
gcc -Wall -Wextra -std=c23 -pedantic -o build/main %SRC_FILES%
