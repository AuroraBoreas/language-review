@echo off
set sum=1+1
echo sum is %sum% 
@rem not work :>
@rem set /?

set /a sum=1+1
echo sum is %sum% 