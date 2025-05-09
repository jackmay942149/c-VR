@echo off
call "./scripts/generate-vs-sln.bat"
cmake --build vs
cd build
"c-VR.exe"
