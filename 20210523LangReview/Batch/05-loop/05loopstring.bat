@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal
    echo main running...
    
    for /f "tokens=1,2* delims= " %%i in ("Irure officia do nisi eiusmod officia duis occaecat veniam aliquip labore labore eu elit.") do (
        echo %%i %%j
    )
    echo. && echo finished
endlocal
goto :eof