@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM if no arguments, program must fail
%MyProgram% > nul && goto err
echo Test1 passed - If no arguments, program must fail

REM if the number of allowed parameters is more than three, there will be an error
%MyProgram% file1 file2 file3 > nul && goto err
echo Test2 passed - if the number of allowed parameters is more than three, there will be an error

REM start the  program with different files
%MyProgram% file1.txt file2.txt > nul && goto err
echo Test3 passed - start the  program with different files

REM start the  program with equal files
%MyProgram% file1(test).txt file2(test).txt > nul || goto err
echo Test4 passed - start the  program with equal files

exit /B 0

:err
echo test failed
exit /B 1