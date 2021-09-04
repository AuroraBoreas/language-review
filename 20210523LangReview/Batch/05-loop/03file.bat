@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    for /f "eol=; tokens=1,2* delims=," %%i in (bank.csv) do (
        @echo %%i %%j %%k
    )

    for /f "usebackq delims==" %%i in ('hello world fuck you scy') do (
        @echo %%i
    )
    echo.
    echo finished
endlocal
goto :eof