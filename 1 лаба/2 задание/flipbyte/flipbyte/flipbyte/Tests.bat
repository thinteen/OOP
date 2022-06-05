@echo off

REM ���� � ����������� ��������� ���������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"

REM ������ �� ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 

REM ���� 1: ������ ��� ����������
%MyProgram% > nul && goto err
echo "Test 1 passed: running without arguments"

REM ���� 2: ������ c ������� �����������
%MyProgram% 4 5 6 > nul && goto err
echo "Test 2 passed: running with extra arguments 4 5 6"

REM ���� 3: ������ � ��������� ����������� ��������
%MyProgram% -10 > nul && goto err
echo "Test 3 passed: starting with an invalid value -10"

REM ���� 4: ������ � ��������� ����������� ��������
%MyProgram% abc > nul && goto err
echo "Test 4 passed: starting with an invalid value abc"

REM ���� 5: ������ � ��������� ����������� ��������
%MyProgram% "" > nul && goto err
echo "Test 5 passed: starting with an invalid value ..."

REM ���� 6: ������ � ��������� ����������� ��������
%MyProgram% 350 > nul && goto err
echo "Test 6 passed: starting with an invalid value 350"

REM ���� 7: ������ � ��������� ��������� ��������
%MyProgram% 6 > "%TEMP%\output.txt" || goto err
set /p result=<"%TEMP%\output.txt"
if not %result% == 96 goto err
echo "Test 7 passed: starting with a valid value 6"

REM ���� 8: ������ � ��������� ��������� ��������
%MyProgram% 65 > "%TEMP%\output.txt" || goto err
set /p result=<"%TEMP%\output.txt"
if not %result% == 130 goto err
echo "Test 8 passed: starting with a valid value 65"

REM ����� ������ �������
echo "All tests passed successfull"
exit /B 0

REM ������� ���� � ������ ������
:err
echo "Test failed"
exit /B 1

REM ������ ������, ��������� ��������