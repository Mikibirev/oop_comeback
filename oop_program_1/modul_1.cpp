#include <iostream>
#define _USE_MATH_DEFINES  // Подключение математических констант
#include <math.h>		   // Подключение математических операций

using namespace std;	   // Пространство имён std

namespace kib {                           // Собственное пространство имён
	double period_l(float l) {            // Функция, возвращающая период
		const double g = 9.80665;		  // Ускорение свободного падения
		return 2 * M_PI * sqrt(l / g);	  // Формула периода маятника
	}
}