SET COMPILE_PATH=\\192.168.3.107\zc\338\Android_MALAIXIYA\
:: xcopy   %COMPILE_PATH%\device\mstar\watermelon\customized_data.tar.gz                                                                       .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\INI\panel\FullHD_CMO216_H1L01.ini                                              .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\INI\misc\boot0.jpg                                                             .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\INI\ZVT\CUS_IR\                                                                .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\INI\ZVT\FACTORY_IR\                                                            .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\kernel_Xgt\3.10.40\drivers\media\rc\keymaps\rc-mstar-tv.c                                               .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\kernel_Xgt\mstar2\drv\ir\IR_MSTAR_DTV.h                                                                 .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\device\mstar\watermelon\keypad.h                                                                                     .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\messi\MST091B_10ASXG_TVOS_DTMB\SN_Keypad_Messi_MST091B_10ASXG.h                .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\messi\MST091B_10ASXG_TVOS_DTMB\model\Customer_1.ini                            .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\board\INI\misc\user_setting.sql                                                      .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\out\target\product\watermelon\system\build.prop                                                                      .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\target\PM51_forBootFromROM\messi\PM.bin                                                       .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\mboot\MstarCore\src\api\msAPI_Power.c                                                                   .\backup_config\  /v /Y
echo %errorlevel%
xcopy   %COMPILE_PATH%\vendor\mstar\supernova\projects\msrv\control\src\MSrv_Control_common.cpp                                             .\backup_config\  /v /Y
echo %errorlevel%

rem 提取配置信息
echo IR:
echo Logo:
echo Panel:
echo keyboard:
echo Language:
echo Area:
echo density:

xcopy %COMPILE_PATH%\..\images\kitkat\watermelon\MstarUpgrade.bin                                                                            .\Bin\  /v /Y
rem 打包配置文件中
md5sum  .\Bin\MstarUpgrade.bin  > info.txt
set /p str=<info.txt
del info.txt
.\7-Zip\7z.exe a %str:~1,32%.7z  .\backup_config\*


pause