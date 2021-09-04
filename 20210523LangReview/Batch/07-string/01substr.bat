@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal

    echo main running...
    set txt=hello world
    echo !txt:~6,3!

    set new=!txt:world=zhang!
    echo !new!
    
    echo.
    echo finished
goto :eof