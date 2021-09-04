@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    set txt="hell world"

    for /f "usebackq tokens=*" %%g in ('!txt!') do set var=%%~g

    echo !var!
endlocal
goto :eof