::关闭回显
@echo off

::拷贝依赖库
call preBuild.bat

::编译eLTE_Player.ocx控件Debug
echo "--------- 编译 eLTE_Player.ocx Debug start ---------"
@"%VS100COMNTOOLS%\..\IDE\devenv.com" .\eLTE_Player.sln /Rebuild "Debug|Win32"
echo "--------- 编译 eLTE_Player.ocx Debug  end  ---------"

::编译eLTE_Player.ocx控件Release
echo "--------- 编译 eLTE_Player.ocx Release start ---------"
@"%VS100COMNTOOLS%\..\IDE\devenv.com" .\eLTE_Player.sln /Rebuild "Release|Win32"
echo "--------- 编译 eLTE_Player.ocx Release  end  ---------"

::打包eLTE_Player.ocx控件Debug
echo "--------- 打包 eLTE_Player.ocx Debug start ---------"
(chdir output\debug)
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip *.ini *.dll *.ocx *.bat *.conf
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip conf\*.ini conf\*.cnf conf\*.txt conf\*.xsd conf\*.xml
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip conf\*.ini conf\error\*.xml conf\error\*.xsd
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip conf\*.ini conf\cm_service\*.xml conf\cm_service\en\*.xml
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip Lang\*.ini
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip Skin\*.png
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip Skin\ToolBar\*.png
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip Skin\Caption\*.png
(chdir ..\..\)
echo "--------- 打包 eLTE_Player.ocx Debug  end  ---------"

::打包eLTE_Player.ocx控件Release
echo "--------- 打包 eLTE_Player.ocx Release start ---------"
(chdir output\release)
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip *.ini *.dll *.ocx *.bat *.conf
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip conf\*.ini conf\*.cnf conf\*.txt conf\*.xsd conf\*.xml
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip conf\*.ini conf\error\*.xml conf\error\*.xsd
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip conf\*.ini conf\cm_service\*.xml conf\cm_service\en\*.xml
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip Lang\*.ini
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip Skin\*.png
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"release" ..\..\eLTE_Player.zip Skin\ToolBar\*.png
"c:\Program Files\WinRAR\Rar.exe" u -s- -m1 -ap"debug" ..\..\eLTE_Player.zip Skin\Caption\*.png
(chdir ..\..\)
echo "--------- 打包 eLTE_Player.ocx Release  end  ---------"

pause
