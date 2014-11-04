@echo off

::¿½±´debug¿â
xcopy /Y ..\..\platform\SDK\*.dll .\output\debug\
xcopy /Y ..\..\platform\SDK\*.ini .\output\debug\
xcopy /Y ..\..\platform\SDK\conf\*.ini .\output\debug\conf\
xcopy /Y ..\..\platform\SDK\conf\*.cnf .\output\debug\conf\
xcopy /Y ..\..\platform\SDK\conf\*.txt .\output\debug\conf\
xcopy /Y ..\..\platform\SDK\conf\*.xsd .\output\debug\conf\
xcopy /Y ..\..\platform\SDK\conf\*.xml .\output\debug\conf\
xcopy /Y ..\..\platform\SDK\conf\error\*.xml .\output\debug\conf\error\
xcopy /Y ..\..\platform\SDK\conf\error\*.xsd .\output\debug\conf\error\
xcopy /Y ..\..\platform\SDK\conf\cm_service\*.xml .\output\debug\conf\cm_service\
xcopy /Y ..\..\platform\SDK\conf\cm_service\en\*.xml .\output\debug\conf\cm_service\en\

xcopy /Y ..\..\platform\IVS_MP\dll\*.dll .\output\debug\
xcopy /Y ..\..\platform\IVS_MP\dll\*.conf .\output\debug\

xcopy /Y ..\..\open_src\log4cpp-1.1.1\log4cpp\msvc10\log4cpp\Debug\*.dll .\output\debug\

xcopy /Y ..\..\third_party\"Microsoft Visual Studio 10.0"\mfc100ud.dll .\output\debug\


::¿½±´release¿â
xcopy /Y ..\..\platform\SDK\*.dll .\output\release\
xcopy /Y ..\..\platform\SDK\*.ini .\output\release\
xcopy /Y ..\..\platform\SDK\conf\*.ini .\output\release\conf\
xcopy /Y ..\..\platform\SDK\conf\*.cnf .\output\release\conf\
xcopy /Y ..\..\platform\SDK\conf\*.txt .\output\release\conf\
xcopy /Y ..\..\platform\SDK\conf\*.xsd .\output\release\conf\
xcopy /Y ..\..\platform\SDK\conf\*.xml .\output\release\conf\
xcopy /Y ..\..\platform\SDK\conf\error\*.xml .\output\release\conf\error\
xcopy /Y ..\..\platform\SDK\conf\error\*.xsd .\output\release\conf\error\
xcopy /Y ..\..\platform\SDK\conf\cm_service\*.xml .\output\release\conf\cm_service\
xcopy /Y ..\..\platform\SDK\conf\cm_service\en\*.xml .\output\release\conf\cm_service\en\

xcopy /Y ..\..\platform\IVS_MP\dll\*.dll .\output\release\
xcopy /Y ..\..\platform\IVS_MP\dll\*.conf .\output\release\

xcopy /Y ..\..\open_src\log4cpp-1.1.1\log4cpp\msvc10\log4cpp\release\*.dll .\output\release\

xcopy /Y ..\..\third_party\"Microsoft Visual Studio 10.0"\mfc100u.dll .\output\release\


::pause
