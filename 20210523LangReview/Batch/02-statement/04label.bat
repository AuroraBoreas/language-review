:label#01
@echo off
dir
echo.
echo hello zhang liang
echo.
echo enter two numbers pls!
echo.
echo enter number1
set /p number1=
echo enter number2
set /p number2=
set /a rv = number1 + number2
echo result is %rv%
pause