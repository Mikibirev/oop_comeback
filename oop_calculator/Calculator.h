/* ---------------------------------
-- Студент:         Кибирев М.Г.  --
-- Преподаватель:   Ветров С.В.   --
--------------------------------- */
#pragma once
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

using big = long double;

// ----- Класс калькулятора
class Calculator
{
private:
    // стек развёрнутой постфиксной записью
    std::stack<std::string> postfix_reverse;

    // стек для операций
    std::stack<char> operations;

    // буфер для хранения чисел
    std::string num_buf;

    // проход всего выражения
    bool availabilityOfNumbers;

    // счётчики для проверки выражения
    unsigned num_count;
    unsigned oper_count;

	// стек для хранения постфиксного выражения: 2 2 +
    std::stack<std::string> postfix;

    // создаём стек-буфер для вычисления
    std::stack<big> buf_calc;

    // ... переменную для верхнего числа из стека
    big ultimate;
    // ... переменную для предверхнего числа из стека
    big penultimate;

	// алгоритм Дейкстра
    void Deijkstra(std::string& __inf);

	// приоритет операций
	short Priority(char& __oper);

public:
    // конструктор по умолчанию
    Calculator();

	// метод вычисления выражения
    big Calculate(std::string& __inf);

    // метод сброса полей калькулятора
    void Clear();
};

