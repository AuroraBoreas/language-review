@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo hello world^^!
    set /a first=0
    set /a last=10

    :loop
        if !first! lss !last! (
            echo !first!
            set /a first=!first! + 1
            goto :loop
        )

    echo.
    echo bye world^^!
endlocal
goto :eof