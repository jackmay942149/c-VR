@echo off
cmake -S . -B ninja -G Ninja -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=%cd%\build
cmake --build ninja
