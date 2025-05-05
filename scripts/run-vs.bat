@echo off
call "./scripts/generate-vs-sln.bat"
cmake --build vs
"./build/c-VR.exe"
