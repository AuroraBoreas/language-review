@echo off
goto main

:function
    set /a rv = %~1 + %~2
    echo result is %rv%
goto :eof

:main
    echo this is main function
    call :function 42 69
    echo main function ended
goto :eof