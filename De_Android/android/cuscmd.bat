
rd /s/q tmp_tvcustomer
7z X -y tvcustomer -otmp_customer
echo "tvcustomer Decompress Successful"

rd /s/q tmp_tvconfig
7z X -y tvconfig -otmp_tvconfig
echo "tvconfig Decompress Successful"

rd /s/q tmp_system
7z X -y system -otmp_system
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
del tvcustomer
del cache
del ZVT_FACTORY_AT.txt
del factoryautoupdate.txt
del script.bat
echo "Decompress Successful"