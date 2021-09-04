@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    for /f "delims= " %%i in ('dir') do (
        @echo %%i
    )
endlocal
goto :eof