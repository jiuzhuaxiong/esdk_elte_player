::�رջ���
@echo off

::����������
call preBuild.bat

::����eLTE_Player.ocx�ؼ�Debug
echo "--------- ���� eLTE_Player.ocx Debug start ---------"
@"%VS100COMNTOOLS%\..\IDE\devenv.com" .\eLTE_Player.sln /Rebuild "Debug|Win32"
echo "--------- ���� eLTE_Player.ocx Debug  end  ---------"

::����eLTE_Player.ocx�ؼ�Release
echo "--------- ���� eLTE_Player.ocx Release start ---------"
@"%VS100COMNTOOLS%\..\IDE\devenv.com" .\eLTE_Player.sln /Rebuild "Release|Win32"
echo "--------- ���� eLTE_Player.ocx Release  end  ---------"

::���eLTE_Player.ocx�ؼ�Debug
echo "--------- ��� eLTE_Player.ocx Debug start ---------"
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
echo "--------- ��� eLTE_Player.ocx Debug  end  ---------"

::���eLTE_Player.ocx�ؼ�Release
echo "--------- ��� eLTE_Player.ocx Release start ---------"
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
echo "--------- ��� eLTE_Player.ocx Release  end  ---------"

pause
