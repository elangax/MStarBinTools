@echo off
echo WIFIMAC序号查询工具
echo 请将本文将放置于U盘根目录下
echo 版本:V1.0
rem set /p search_str=<mac.txt
set /p search_str=请输入MAC地址（包含冒号）:
findstr /M %search_str% .\WIFIMAC\*.dat >temp.txt
set /p str=<temp.txt
del temp.txt
echo %str:~-10,-4% >TEXT.txt
pause
