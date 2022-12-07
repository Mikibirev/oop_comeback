#pragma once

using namespace std;		// Использовать стандартное пространство имён std
using arr = vector<int>;	// Упрощение vector<int> до arr с помощью using-объявления
namespace kib {				// Использовать собственное пространство имён kib

	void random_vec(arr& a, int l, int r);		// Процедура заполнения вектора случайными значениями
	void output_screen(const arr& a);			// Процедура вывода элементов вектора a на экран через пробел
	int sum(const arr& a);						// Функция суммирования l элементов вектора a
	void output_file(const arr& a, string f);	// Процедура вывода вектора a в файл f
	void input_file(arr& a, string f);			// Процедура записи данных из файла f в вектор a
}