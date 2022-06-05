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
echo "Test 1 passed: without arguments"

REM Тест 2: Запуск c лишними аргументами
%MyProgram% matrix1.txt matrix2.txt matrix3.txt > nul && goto err
echo "Test 2 passed: extra arguments"

REM Тест 3: Запуск c недостающими аргументами
%MyProgram% matrix1.txt > nul && goto err
echo "Test 3 passed: small number of arguments"

REM Тест 4: Запуск с пустым файлом
%MyProgram% empty.txt > nul && goto err
echo "Test 4 passed: invalid action type"

REM Тест 5: Запуск c несуществующими файлами
%MyProgram% missing1.txt missing2.txt > nul && goto err
echo "Test 5 passed: nonexistent file"

REM Тест 6: Запуск c файлами содержащими матрицы
%MyProgram% matrix1.txt matrix2.txt > "%TEMP%\output.txt" || goto err
fc answer1.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 6 passed: starting with matrices"

REM Тест 7: Умножение на нулевую матрицу
%MyProgram% matrix1.txt null.txt > "%TEMP%\output.txt" || goto err
fc answer2.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 7 passed: zero matrix"

REM Тест 8: Умножение на единичную матрицу
%MyProgram% matrix1.txt ones.txt > "%TEMP%\output.txt" || goto err
fc answer3.txt "%TEMP%\output.txt" > nul || goto err
echo "Test 8 passed: ones matrix"

REM Тесты прошли успешно
echo "All tests passed successfull"
exit /B 0

REM Переход сюда в случае ошибки
:err
echo "Test failed"
exit /B 1/