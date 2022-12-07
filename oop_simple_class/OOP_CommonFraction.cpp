// cделано Кибиревым Михаилом из ВМК-20
#include <iostream>
#include "CommonFraction.h"
#include <fstream>

int main() {
    setlocale(0, "");
    using namespace std;
    const string& namefile = "data.txt";                                        // название файла для ввода/вывода
    const int n = 10;

    CommonFraction arr[10];
    CommonFraction* array = new CommonFraction[n];                              // массив объектов класса CommonFraction
    CommonFraction** ptr_array = new CommonFraction * [n];                      // массив указателей на объекты

    arr[5].add_frac(arr[7]);
    ptr_array[10]->add_frac(*ptr_array[9]);

    try {
        array[0].set_frac(8, 16);                                               // обработка исключений ввода главной дроби
    }
    catch (logic_error err) {
        cout << "Ошибка ввода знаменателя: " << err.what() << endl;             // обработка исключения при выбрасывании ошибки
        system("pause");                                                        // фиксация консоли
        return 0;                                                               // завершение программы
    }

    try {
        array[1].set_frac(4, 10);                                               // обработка исключений ввода дополнительной дроби
    }
    catch (logic_error err) {
        cout << "Ошибка ввода знаменателя: " << err.what() << endl;             // обработка исключений при выбрасывании ошибки
        system("pause");                                                        // фиксация консоли
        return 0;                                                               // завершение программы
    }

    CommonFraction* ptr = new CommonFraction(2, 5);
    CommonFraction output;                                                      // конструктор по умолчанию
    
    for (int i = 0; i < n; i++)                                                 // всем элементам массива указателей
        ptr_array[i] = &array[i];                                               // присвоить ссылку на элемент массива
    cout << "Указатель на первое число: " 
        << ptr_array[0]->string_frac() << endl;                                 // вывести на экран первый элемент по ссылке

    cout << "Число №1: " << array[0].string_frac() << endl;                     // вывод главной дроби
    array[0].reduce();                                                          // сокращение главной дроби
    cout << "Число №1: " << array[0].string_frac() << endl;                     // вывод сокращённой главной дроби
    cout << "Число №2: " << array[1].string_frac() << endl;                     // вывод дополнительной дроби
    array[1].reduce();                                                          // сокращение дополнительной дроби
    cout << "Число №2: " << array[1].string_frac() << endl;                     // вывод сокращённой дополнительной дроби
    output = array[0].add_frac(array[1]);                                       // сложить дроби №1 и №2
    cout << "Сумма: " << output.string_frac() << endl;                          // вывести результат на экран
    output = array[0].sub_frac(array[1]);                                       // вычесть из дроби №1 дробь №2
    cout << "Разница: " << output.string_frac() << endl;                        // вывести результат на экран
    output = array[0].mul_frac(array[1]);                                       // перемножить дроби №1 и №2
    cout << "Умножение: " << output.string_frac() << endl;                      // вывести результат на экран
    output = array[0].div_frac(array[1]);                                       // разделить дробь №1 на дробь №2
    cout << "Деление: " << output.string_frac() << endl;                        // вывести результат на экран
    output = array[0].return_more(array[1]);                                    // вернуть большую или равную дробь
    cout << "Большее: " << output.string_frac() << endl;                        // вывести результат на экран
    output = array[0].return_less(array[1]);                                    // вернуть меньшую или равную дробь
    cout << "Меньшее: " << output.string_frac() << endl;                        // вывести результат на экран
    cout << "Десятичная форма числа №1: " << array[0].decimal_frac() << endl;   // перевести дробь №1 в десятичную форму
    cout << "Десятичная форма числа №2: " << array[1].decimal_frac() << endl;   // перевести дробь №2 в десятичную форму

    array[0].frac_to_file(namefile);            			     // вывод дроби в файл
    output.frac_from_file(namefile);                   		     // вывод дроби из файла
    cout << "Вывод из файла: " << output.string_frac() << endl;  // вывод полученной дроби

    delete[] ptr_array;                 // очистка памяти от массива указателей
    delete[] array;                     // очистка памяти от массива дробей

    system("pause");
    return 0;
}