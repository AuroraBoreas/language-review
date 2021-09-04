@echo off
setlocal enabledelayedexpansion
goto :main

:main
    call callee.bat var "hello zhang liang"
    echo !var!
goto :eof