@echo off
cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
move /Y ".\build\compile_commands.json" .
