@echo off
set SRC_FILES=src/main.c 
gcc -Wall -Wextra -Werror -std=c23 -pedantic -o build/main %SRC_FILES%
