@REM formats the AStyleX C++ source code
@echo off

set progdir=..\..\AStyle\build\vs2008\bin
set srcdir1=..\src-c
set srcdir2=..\src-cx


%progdir%\AStyle  -l  %srcdir1%\*.cpp
%progdir%\AStyle  -l  %srcdir2%\*.cpp  %srcdir2%\*.h

echo -
echo -
echo * * * *  end of Format Cpp  * * * *
pause