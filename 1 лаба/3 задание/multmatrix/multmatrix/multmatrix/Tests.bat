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
echo "Test 1 passed: without arguments"

REM ���� 2: ������ c ������� �����������
%MyProgram% matrix1.txt matrix2.txt matrix3.txt > nul && goto err
echo "Test 2 passed: extra arguments"

REM ���� 3: ������ c ������������ �����������
%MyProgram% matrix1.txt > nul && goto err
echo "Test 3 passed: small number of arguments"

REM ���� 4: ������ � ������ ������
%MyProgram% empty.txt > nul && goto err
echo "Test 4 passed: invalid action type"

REM ���� 5: ������ c ��������������� �������
%MyProgram% missing1.txt missing2.txt > nul && goto err
echo "Test 5 passed: nonexistent file"

REM ���� 6: ������ c ������� ����������� �������
%MyProgram% matrix1.txt matrix2.txt > "%TEMP%\output.txt" || goto err
fc answer1.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 6 passed: starting with matrices"

REM ���� 7: ��������� �� ������� �������
%MyProgram% matrix1.txt null.txt > "%TEMP%\output.txt" || goto err
fc answer2.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 7 passed: zero matrix"

REM ���� 8: ��������� �� ��������� �������
%MyProgram% matrix1.txt ones.txt > "%TEMP%\output.txt" || goto err
fc answer3.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 8 passed: ones matrix"

REM ����� ������ �������
echo "All tests passed successfull"
exit /B 0

REM ������� ���� � ������ ������
:err
echo "Test failed"
exit /B 1/