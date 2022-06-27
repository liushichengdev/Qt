# Qt Learning
0. Website: qt.io
1. examples: https://code.qt.io/cgit/qt/qtbase.git/tree/?h=6.3
2. How to deploy on Windows Operating System
	2.1 WinDeployQt: exact all the dependencies
		2.1.1 prepare a empty folder
		2.1.2 copy release.exe into the empty folder
		2.1.3 run windeployqt.exe
			$$C:\Qt\6.3.1\msvc2019_64\bin\windeployqt.exe release.exe
	
	2.2 InstallerFrameWork: build installer
		2.2.1 prepare the folder which contains config and packages
		2.2.2 edit config.xml in the folder of config
		2.2.3 create a new folder, named com.Developer.ApplicationName, containing data folder and meta folder
		2.2.4 copy all the files from step 2.1.3 into folder ./packages/com.Developer.ApplicationName/data/
		2.2.5 prepare installcript.qs, license.txt, package.xml and page.ui
		2.2.6 run installerbase.exe
			$$C:\Qt\Tools\QtInstallerFramework\4.4\bin\installerbase.exe -c ./config/config.xml -p ./packages/com.ApplicationName/ InstallerName

Practices:
1. First Qt GUI Application is base
2. Guess Number Application includes source code, windeployqt and installerfarework.
3. HelloQt: cpp vs QTextStream
4. QList
5. QObject
6. QString
7. QStringView
8. QtSmartPointers
9. ParentChild
10. QByteArray
11. QDeleteAll
12. QsqlDatabase
13. InventoryApp
14. QMap
15. QTextStream
16. QDetermingOS
17. QStorageInfo
18. QDir
19. 
