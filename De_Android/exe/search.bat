@echo off
echo WIFIMAC��Ų�ѯ����
echo �뽫���Ľ�������U�̸�Ŀ¼��
echo �汾:V1.0
rem set /p search_str=<mac.txt
set /p search_str=������MAC��ַ������ð�ţ�:
findstr /M %search_str% .\WIFIMAC\*.dat >temp.txt
set /p str=<temp.txt
del temp.txt
echo %str:~-10,-4% >TEXT.txt
pause
