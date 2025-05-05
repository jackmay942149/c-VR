@echo off
cmake -S . -G "Visual Studio 17 2022" -A x64 -B vs -DCMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG=%cd%\build
