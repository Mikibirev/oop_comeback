#include <iostream>
#include <cassert>
#include "header_1.h"      // Подключение модуля

int main() {
	using namespace std;   // Пространство имён std
	using namespace kib;   // Собственное пространство имён
	setlocale(0,"");	   // Русская локализация

//	assert(fabs(period_l(10) - 6.34482) < 0.00001);
//	assert(fabs(period_l(0.007) - 0.16786) < 0.00001);
//	assert(fabs(period_l(65000000) - 16176.18886) < 0.00001);
	
	float l;                             // Переменная длины маятника
	do {								 // Повторять...
		cout << "Длина маятника: ";		 // Обращение к пользователю
		cin >> l;						 // Ввод длины маятника
	} while (l <= 0);					 // ...пока не больше нуля
	cout << "Период маятника: "			 
		<< period_l(l) << endl;			 // Вывод периода через формулу
	
	system("pause");       // Зафиксировать консоль
	return 0;
}