#include <iostream>
#include <time.h>			// Подключение рандома
#include "header_modul.h"	// Подключение модуля

int main() {
	using namespace std;		// Стандартное пространство имён
	using namespace kib;		// Собственное пространство имён
	setlocale(0, "");			// Русская локализация
	srand(unsigned(time(0)));	// Псевдослучайность

	int lnt;	// Длина массива, lnt(length) - длина
	do {
		cout << "Длина массива: ";		// Обращение к пользователю...
			cin >> lnt;					// Пока длина не положительна
	} while (lnt <= 0);
	
	int rng;	// Диапазон значений, rng(range) - диапазон
	do {
		cout << "Диапазон значений: ";	// Обращение к пользователю...
		cin >> rng;						// Пока диапазон не положителен
	} while (rng <= 0);

	int* array = new int[lnt];		// Объявление массива
	filling(array, lnt, rng);		// Процедура заполнения массива
	output(array, lnt);				// Процедура вывода массива
	cout << "Сумма элементов: "		// Обращение к пользователю...
		<< sum(array, lnt) << endl;	// Сумма элементов массива

	delete[] array;			// Очистка памяти от массива
	array = 0;				// Обнуление массива
	system("pause");		// Зафиксировать консоль
	return 0;
}