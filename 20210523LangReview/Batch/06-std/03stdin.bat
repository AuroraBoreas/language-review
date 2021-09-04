@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    
    ::stdout
    ::stderr
    ::stdin
    set out=out3.txt
    @REM echo hello world^^! > !out!
    echo y > !out!
    choice < !out!
    @REM start !out!

endlocal
goto :eof