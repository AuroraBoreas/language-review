@echo off
goto :main

:func
setlocal
    echo   inside func
endlocal & set /a x=%x% + 1
goto :eof

:main
    echo main is running..
    set /a x=1
    call :func x
    echo X is %x%
goto :eof