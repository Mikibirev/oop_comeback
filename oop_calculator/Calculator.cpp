/* ---------------------------------
-- Студент:         Кибирев М.Г.  --
-- Преподаватель:   Ветров С.В.   --
--------------------------------- */
#include "Calculator.h"

/* ---------------------------------------
1. Арифметические операции;             --
2. Возведение в любую степень;          --
3. Тригонометрические функции;          --
4. Обработка исключительных ситуаций;   --
------------------------------------------
5. История вычислений;                  --
6. Разбор математических выражений.     --
--------------------------------------- */

// конструктор по умолчанию
Calculator::Calculator()
{
    num_buf = "";

    availabilityOfNumbers = 0;

    num_count = 0;
    oper_count = 0;

    ultimate = 0.00;
    penultimate = 0.00;
}

// приоритет символов
short Calculator::Priority(char& __oper)
{
    switch (__oper)
    {
    // скобка во избежание ошибки
    case '(':
        return 0;
        break;
    // бинарные операции
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    // унарные операции
    case '~':
        return 4;
        break;
    case 'c':
        return 4;
        break;
    case 's':
        return 4;
        break;
    case 't':
        return 4;
        break;
    case 'g':
        return 4;
        break;
    // числа
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 5;
        break;
    default:
        return -1;
        break;
    }
    throw std::invalid_argument("ERROR: unknown symbol");
    return -1;
}

// метод преобразования инфиксного выражения в постфиксное
void Calculator::Deijkstra(std::string& __inf)
{
    // ------ проверка наличия цифр в выражении
    // --
    // --
    availabilityOfNumbers = 0;
    for (auto i = __inf.begin(); i <= __inf.end(); i++)
    {
        if ('0' <= *i && *i <= '9')
            availabilityOfNumbers = 1;
    }
    if (availabilityOfNumbers == 0)
        throw std::invalid_argument("ERROR: where are the numbers?");

    // ----- преобразование инфиксного выражения в постфикное
    // --
    // --
    for (auto i = __inf.begin(); i <= __inf.end(); i++)
    {
        if (i == __inf.end())
        {
            if (num_buf.empty())
                break;
            else
            {
                // если буфер не пустой в конце прохода строки,
                // выталкиваем число из этого буфера в стек
                postfix_reverse.push(num_buf);
                // очищаем строку
                num_buf.clear();
                break;
            }
        }
        // если найдено число или плавающая точка
        if (('0' <= *i && *i <= '9') || *i == '.')
        {
            // занести её в буфер
            num_buf += *i;
            continue;
            // если число кончилось или не найдено
            // проверяем буфер на заполненность
        }
        else if (!num_buf.empty())
        {
            // если буфер не пустой,
            // выталкиваем число в стек
            postfix_reverse.push(num_buf);
            // очищаем строку
            num_buf.clear();
        }
        // если на текущей позиции открывающаяся скобка
        if (*i == '(')
        {
            operations.push(*i);
            continue;
        }
        // если на текущей позиции закрывающаяся скобка
        if (*i == ')')
        {
            if (operations.empty())
                throw std::invalid_argument("ERROR: extra right bracket");
            // выталкиваем из стека все операторы
            // до открывающейся скобки
            while (operations.top() != '(')
            {
                num_buf = operations.top();
                postfix_reverse.push(num_buf);
                operations.pop();
                if (operations.empty())
                    throw std::invalid_argument("ERROR: extra right bracket");
            }
            // удаляем закрывающуюся скобку
            operations.pop();
            num_buf.clear();
            continue;
        }
        // если стек операций пуст
        if (operations.empty())
        {
            // просто закидываем операцию в стек
            operations.push(*i);
            continue;
        }
        // если стек операций не пуст
        // выталкиваем все операторы, имеющие приоритет выше
        else {
            // пока приоритет операции в стеке выше рассматриваемого
            while (!operations.empty())
            {
                if (Priority(operations.top()) >= Priority(*i))
                {   // выталкиваем оператор в выходной стек
                    num_buf = operations.top();
                    postfix_reverse.push(num_buf);
                    operations.pop();
                }
                else
                    break;
            }
            // записываем оператор в стек операций
            operations.push(*i);
            num_buf.clear();
        }
    }

    // ----- проверка соответствия количества операций и чисел
    // --
    // --
    if (!operations.empty() && postfix_reverse.empty())
        throw std::invalid_argument("ERROR: extra operation");

    // выталкиваем оставшиеся операторы
    while (!operations.empty())
    {
        // выталкиваем оператор в выходной стек
        num_buf = operations.top();
        postfix_reverse.push(num_buf);
        operations.pop();
    }

    // ----- заполняем стек с постфиксной записью
    // --
    // --
    while (!postfix_reverse.empty())
    {
        // заодно проверим, соответствуют ли операции числам
        switch (Priority(postfix_reverse.top()[0]))
        {
        // если найдена скобка (не дай Бог)
        case '0':
            throw std::invalid_argument("ERROR: extra right bracket");
            break;
        case '1':
        case '2':
        case '3':
        // если бинарная операция
            oper_count += 2;
            break;
        // если унарная операция
        case '4':
            oper_count += 1;
        // если число
        case '5':
            num_count += 2;
            break;
        }
        // если не соответствует, то ошибка
        if (oper_count > num_count)
            throw std::invalid_argument("ERROR: extra operations");

        this->postfix.push(postfix_reverse.top());
        postfix_reverse.pop();
    }
}

big Calculator::Calculate(std::string& __inf)
{
    // преобразуем инфиксную строку в постфиксную
    Deijkstra(__inf);

    // пока постфиксная запись не будет пройдена
    while (!postfix.empty())
    {
        // если текущий элемент является числом
        if ('0' <= postfix.top()[0] && postfix.top()[0] <= '9')
        {
            // заносим его в стек вычисления
            buf_calc.push(stold(postfix.top()));
            // удаляем из постфиксной записи
            postfix.pop();
        }
        // если текущий элемент является операцией
        else
        {
            // берём последнее число из стека
            ultimate = buf_calc.top();
            buf_calc.pop();
            // если есть предпоследнее число
            if (!buf_calc.empty())
            {
                // то его тоже берём
                penultimate = buf_calc.top();
            }
            // обрабатываем операцию
            switch (postfix.top()[0])
            {
            case '(':
                throw std::invalid_argument("Error: extra left breacket");
                break;
            // ... сложения
            case '+':
                buf_calc.pop();
                buf_calc.push(penultimate + ultimate);
                break;
            // ... вычитания
            case '-':
                buf_calc.pop();
                buf_calc.push(penultimate - ultimate);
                break;
            // ... умножения
            case '*':
                buf_calc.pop();
                buf_calc.push(penultimate * ultimate);
                break;
            // ... деления
            case '/':
                buf_calc.pop();
                if (ultimate == 0)
                    throw std::invalid_argument("ERROR: division by zero");
                buf_calc.push(penultimate / ultimate);
                break;
            case '^':
                buf_calc.pop();
                buf_calc.push(pow(penultimate, ultimate));
                break;
            // ... унарного минуса
            case '~':
                buf_calc.push(ultimate * -1);
                break;
            // ... косинуса
            case 'c':
                buf_calc.push(trunc(10000 * cos(ultimate)) / 10000);
                break;
            // ... синуса
            case 's':
                buf_calc.push(trunc(10000 * sin(ultimate)) / 10000);
                break;
            // ... тангенса
            case 't':
                buf_calc.push(trunc(10000 * tan(ultimate)) / 10000);
                break;
            // ... котангенса
            case 'g':
                buf_calc.push(trunc(10000 * (1 / tan(ultimate))) / 10000);
                break;
            // если найден какой-то инородный символ
            default:
                throw std::invalid_argument("ERROR 2: unknown symbol");
                return -1;
                break;
            }
            postfix.pop();
        } 
    }
    return buf_calc.top();
}

void Calculator::Clear()
{
    // ----- выталкиваем всё из всех стеков
    // --
    // --
    while (!postfix_reverse.empty())
        postfix_reverse.pop();

    while (!operations.empty())
        operations.pop();

    while (!postfix.empty())
        postfix.pop();

    while (!buf_calc.empty())
        buf_calc.pop();

    num_buf = "";

    availabilityOfNumbers = 0;

    num_count = 0;
    oper_count = 0;

    ultimate = 0.00;
    penultimate = 0.00;
}
