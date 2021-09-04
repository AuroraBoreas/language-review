@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    
    ::stdout 1
    ::stderr 2
    set out=stdout.txt
    set err=stderr.txt
    @REM dir /b 1>%out% 2>%err%
    dir /b >>%out% 2>>&1

    echo. && echo finished
endlocal
goto :eof