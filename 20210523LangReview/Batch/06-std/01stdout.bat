@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    ::stdout 1
    dir /b 1> bare.txt
    start bare.txt
    echo.
    echo finished
endlocal
goto :eof