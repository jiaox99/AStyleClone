@echo off
REM USE THE SUPPRESSIONS FILE GENERATED BY THE PYTHON PROGRAM

set progdir=C:\Program Files (x86)\Cppcheck
REM source directory must be an absolute path for matching to suppression file
set srcdir=%USERPROFILE%\Projects\AStyle\src

:: "%progdir%\cppcheck"  --version

REM  --enable=all      Enable all checks
REM -f, --force        Force checking on files that have "too many"  configurations.
REM -v, --verbose      More detailed error reports.
REM -j <jobs>          Start [jobs] threads.
REM -q, --quiet        Only print error messages.
REM --report-progress  Report progress messages while checking a file.
REM --xml              Write results in xml to error stream.
REM --suppress=<spec>  Suppress a specific warning.

set options= --enable=all --force --verbose --xml

REM input suppression file
set suppress= --suppressions-list=..\file-py\cppcheck-suppress

:: "%progdir%\cppcheck"  %options%  %suppress%  %srcdir%

"%progdir%\cppcheck"  --help

:: "%progdir%\cppcheck" --check-config  %srcdir%

echo -
pause