@echo off
setlocal enabledelayedexpansion
@rem from now on, variables must access with !var_name! rather than %var_name% 
goto :main

:main
setlocal
    set /a a=10
    set /a b=20
    echo a is %a%
    echo b is %b%
    if %a%==%b% (
        echo a is equal to b
    ) else if %a% neq %b% (
        echo a is not equal to b
    ) else (
        echo i have no idea
    )

    if EXIST 01if.bat ( echo 01if.bat exists)
    echo.
endlocal
goto :eof