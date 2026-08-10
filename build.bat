@echo off
cd /d %~dp0
C:\mingw64\bin\gcc.exe -Wall -g -I include test\test.c src\*.c -o test.exe
if %errorlevel% neq 0 (echo BUILD FAILED & exit /b 1)
test.exe