@echo off
goto :main

:function
    echo this is function
goto :eof

:main
    echo ... this is main function
    call :function
    echo main function done
    echo program ended
goto :eof