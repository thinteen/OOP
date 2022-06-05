@echo off

REM Путь к тестируемой программе передается через 1-й аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 

REM Тест 1: Запуск без аргументов
%MyProgram% > nul && goto err
echo "Test 1 passed: running without arguments"

REM Тест 2: Запуск c лишними аргументами
%MyProgram% 4 5 6 > nul && goto err
echo "Test 2 passed: running with extra arguments 4 5 6"

REM Тест 3: Запуск с передачей невалидного значения
%MyProgram% -10 > nul && goto err
echo "Test 3 passed: starting with an invalid value -10"

REM Тест 4: Запуск с передачей невалидного значения
%MyProgram% abc > nul && goto err
echo "Test 4 passed: starting with an invalid value abc"

REM Тест 5: Запуск с передачей невалидного значения
%MyProgram% "" > nul && goto err
echo "Test 5 passed: starting with an invalid value ..."

REM Тест 6: Запуск с передачей невалидного значения
%MyProgram% 350 > nul && goto err
echo "Test 6 passed: starting with an invalid value 350"

REM Тест 7: Запуск с передачей валидного значения
%MyProgram% 6 > "%TEMP%\output.txt" || goto err
set /p result=<"%TEMP%\output.txt"
if not %result% == 96 goto err
echo "Test 7 passed: starting with a valid value 6"

REM Тест 8: Запуск с передачей валидного значения
%MyProgram% 65 > "%TEMP%\output.txt" || goto err
set /p result=<"%TEMP%\output.txt"
if not %result% == 130 goto err
echo "Test 8 passed: starting with a valid value 65"

REM Тесты прошли успешно
echo "All tests passed successfull"
exit /B 0

REM Переход сюда в случае ошибки
:err
echo "Test failed"
exit /B 1

REM пустая строка, строковые значения