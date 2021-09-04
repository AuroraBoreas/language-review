@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo hello world^^!

    @rem var in for loop must use %% to access
    @REM for %%i in ( 1 2 3 4 5 6 ) do (
    for /l %%i in (1,2,10) do (
        echo %%i
        @REM if %%i equ 3 (
        @REM     goto :eof
        @REM     @rem exit command will break loop and end the session as well
        @REM )
    )
endlocal
goto :eof