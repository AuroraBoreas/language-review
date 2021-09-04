@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    echo y|choice
    echo.
    echo finished
endlocal
goto :eof