# Модуль quadratic_equation

## Функции

- *solve_equation* - позволяет получить **вещественные(действительные)** корни уравнения вида *ax^2 + bx + c = 0*;

## Типы

- *quad_flags* - перечисляемый тип содержажий возможные значения возвращаемые *solve_equation*;

## solve_equation

#### Объявление

- int solve_equation(double a, double b, double c, double *x1, double *x2);

#### Аргументы

- *a,b,c* это переменные типа double которые содержат аргументы квадратного уравнения;

- *x1, x2* указатели на переменные типа double, куда будут записаны вычисленные значения, в случае возникновения исключения QUAD_ERROR они не инициализируются внутри функции;

#### Возвращаемое значение

- Функция возвращает переменную типа int, которая содержит количество существующих корней (неотрицательное значение), или отрицательное значение в случае ошибки.

#### Поведение

- Возвращает QUAD_ERROR, если a,b,c представляют NAN или указатели x1,x2 равны NULL

- Особая обработка случая при a, b или c равном +-INFINITY не производится, вычисленные x1 и x2 могут быть равны +-INFINITY

- В случае если корень один, он будет записан в обе переменные x1 и x2. В случае если корней нет или они не опредлены, никаких операций над x1 и x2 не производится

## Тестирование

- Тесты написаны с использованием check.h;

- Тесты запускаются с использованием Make с целью check;

- *make check*

- Также можно посмотреть отчет о покрытии тестами с использованием lcov, вызвав цель lcov_report,

- Отчет в формате html можно посмотреть через браузер открыв файл index.html в появившейся папке lcov_report.

- Цель quadratic_equation.a собирает статическую библиотеку с таким же именем.

- Тестирование производилось на Ubuntu 22.04 c компилятором gcc, валидация результатов проводилась с использованием WolframAlpha, точность не менее 6 знаков после запятой для чисел с менее 16 значащами цифрами.

***Автор: htwelve tg: @hidtl 18.03.2024***
