@echo off

set src=%2

for /f "usebackq tokens=*" %%g in ('!src!') do set var=%%~g

set %1=!var!