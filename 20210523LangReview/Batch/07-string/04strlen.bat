@echo off

set txt=%2
set /a redundant=5
for /f "usebackq tokens=*" %%g in ('%txt%') do set var=%%~g

echo %2>%TEMP%\tmpfile.txt
for %%g in (%TEMP%\tmpfile.txt) do (
    if %2 equ %%~g (
        set /a redundant=3
    )
    set /a %1_length=%%~zg - redundant
)
del /q %TEMP%\tmpfile.txt
set %1=%var%
