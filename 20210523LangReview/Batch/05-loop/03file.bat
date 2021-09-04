@echo off
setlocal enabledelayedexpansion
goto :main

:main
    echo main running...
    for /f "eol=; tokens=1,2* delims=," %%i in (bank.csv) do (
        @echo %%i %%j %%k
    )
    echo.
    echo finished
goto :eof