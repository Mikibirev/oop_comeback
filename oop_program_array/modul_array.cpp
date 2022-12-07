#include <iostream>

using namespace std;

namespace kib {
	void filling(int* a, int l, int r) {	// Процедура заполнения массива
		for (int i = 0; i < l; i++)			// Заполнение элементов...
			a[i] = rand() % (r + 1);		// Случайными значениями
	}

	void output(int* a, int l) {			// Процедура вывода массива
		for (int i = 0; i < l; i++)			// Каждый элемент массива...
			cout << a[i] << " ";			// Вывести на экран цепочкой
		cout << endl;
	}

	int sum(int* a, int l) {				// Функция суммирования элементов
		int s = a[0];						// Начальное значение суммы...
		for (int i = 1; i < l; i++)			// Первый элемент
			s += a[i];						// Суммируем со следующими
		return s;
	}
}