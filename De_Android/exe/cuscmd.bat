rd /s/q tmp_tvcustomer
.\7-Zip\7z.exe X -y tvcustomer -otmp_customer
echo "tvcustomer Decompress Successful"

rd /s/q tmp_tvconfig
.\7-Zip\7z.exe X -y tvconfig -otmp_tvconfig
echo "tvconfig Decompress Successful"

rd /s/q tmp_system
.\7-Zip\7z.exe X -y system -otmp_system
echo "system Decompress Successful"
rd /s/q config
mkdir config
xcopy tmp_system\build.prop                                  .\config\
xcopy tmp_system\customized_data.tar.gz                      .\config\
xcopy tmp_tvconfig\boot0.jpg                                 .\config\
xcopy tmp_tvconfig\boot1.jpg                                 .\config\
xcopy tmp_tvconfig\boot2.jpg                                 .\config\
xcopy tmp_tvconfig\boot3.jpg                                 .\config\
xcopy tmp_tvconfig\config\model\Customer_1.ini               .\config\
xcopy tmp_tvconfig\config\panel\FullHD_CMO216_H1L01.ini      .\config\
xcopy tmp_customer\Customer\user_setting.sql                 .\config\
xcopy tmp_customer\Customer\ZVT\*                             .\config\ZVT\*   /s   

touch .\config\build.prop
touch .\config\customized_data.tar.gz
touch .\config\boot0.jpg 
touch .\config\boot1.jpg 
touch .\config\boot2.jpg 
touch .\config\boot3.jpg  
touch .\config\Customer_1.ini
touch .\config\FullHD_CMO216_H1L01.ini
touch .\config\user_setting.sql

del 0x*
del system
del RTPM
del recovery
del tvdatabase
del tvservice
del userdata
del lzo_temp
del vsdcard
del boot
del tvconfig
del tvcustomer
del cache
del ZVT_FACTORY_AT.txt
del factoryautoupdate.txt
del script.bat
echo "Decompress Successful"