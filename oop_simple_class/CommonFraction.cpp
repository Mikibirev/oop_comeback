// cделано Кибиревым Михаилом из ВМК-20
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "CommonFraction.h"
using namespace std;

CommonFraction::CommonFraction() {												// конструктор по умолчанию
	set_num(0);																	// числитель равен нулю
	set_dnom(1);																// знаменатель не равен нулю
}

CommonFraction::CommonFraction(const int& numr, const int& dnomr) {				// конструктор по значениям
	set_num(numr);																// числитель
	set_dnom(dnomr);															// знаменатель
}

void CommonFraction::set_frac(const int& numr, const int& dnomr) {				// запись дроби полностью
	set_num(numr);																// числитель
	set_dnom(dnomr);															// знаменатель
	return;
}

void CommonFraction::set_num(const int& numr) {									// запись числителя
	numerator = numr;
	return;
}

void CommonFraction::set_dnom(const int& dnomr) {								// запись знаменателя
	if (dnomr != 0) {															// если знаменатель не равен нулю
		denominator = dnomr;													// записать знаменатель
		return;
	}
	else {																		// если знаменатель равен нулю
		throw logic_error("Знаменатель равен нулю!");							// выброить исключение
	}
}

int CommonFraction::get_num() const {											// вернуть числитель
	return numerator;
}

int CommonFraction::get_dnom() const {											// вернуть знаменатель
	return denominator;
}

void CommonFraction::reduce() {													// сократить дробь
	for (int i = denominator; i > 0; i--) {										// использовать в качесте делителя уменьшаемый знаменатель
		if (numerator % i == 0) {												// если числитель делится на уменьшаемый знаменатель
			if (denominator % i == 0) {											// знаменатель делится на само себя уменьшаемое
				numerator /= i;													// делить числитель на текущее число
				denominator /= i;												// делить знаменатель на текущее число
			}
		}
	}
	return;
}

CommonFraction CommonFraction::return_more(const CommonFraction& n2) const {	// вернуть большее или равное
	double buf, buf_2;
	buf = (double)this->numerator / (double)this->denominator;					// перевести в десятичную форму число №1
	buf_2 = (double)n2.numerator / (double)n2.denominator;						// перевести в десятичную форму число №2
	if (buf >= buf_2) {															// если первое число больше или равно второго
		return *this;															// вернуть первое число
	}
	else {																		// если первое число больше или равно второму
		return n2;																// вернуть второе число
	}
}

CommonFraction CommonFraction::return_less(const CommonFraction& n2) const {	// вернуть меньшее или равное
	double buf, buf_2;
	buf = (double)this->numerator / (double)this->denominator;					// перевести в десятичную форму число №1
	buf_2 = (double)n2.numerator / (double)n2.denominator;						// перевести в десятичную форму число №2
	if (buf <= buf_2) {															// если первое число больше или равно второго
		return *this;															// вернуть первое число
	}
	else {																		// если первое число меньше или равно второму
		return n2;																// вернуть второе число
	}
}

CommonFraction CommonFraction::add_frac(const CommonFraction& n2) const {		// сложить обыкновенные дроби
	CommonFraction num1 = *this, num2 = n2, result;
	if (num1.denominator % num2.denominator == 0) {								// если знаменатель первого числа делится нацело на знаменатель второго
		num2.denominator *= num1.denominator / num2.denominator;				// домножаем знаменатель второго числа до знаменателя первого числа
		num2.numerator *= num1.denominator / num2.denominator;
	}
	else if (n2.denominator % num1.denominator == 0) {							// если знаменатель второго числа делится нацело на знаменатель первого
		num1.denominator *= num2.denominator / num1.denominator;				// домножаем знаменатель первого числа до знаменателя второго числа
		num1.numerator *= num2.denominator / num1.denominator;
	}
	else if (n2.denominator % num1.denominator != 0) {							// если знаменатель первого числа не равен знаменателю второго числа
		int buffer = num1.denominator;											// перемножаем знаменатели друг на друга, домножая числители
		num1.numerator *= num2.denominator;
		num1.denominator *= num2.denominator;
		num2.numerator *= buffer;
		num2.denominator *= buffer;
	}
	result.numerator = num1.numerator + num2.numerator;							// скрадываются числители
	result.denominator = num1.denominator;										// знаменатель является одним и тем же
	result.reduce();															// сокращение полученной дроби
	return result;
}

CommonFraction CommonFraction::sub_frac(const CommonFraction& n2) const {		// сложить обыкновенные дроби
	CommonFraction num1 = *this, num2 = n2, result;
	if (num1.denominator % num2.denominator == 0) {								// если знаменатель первого числа делится нацело на знаменатель второго
		num2.denominator *= num1.denominator / num2.denominator;				// домножаем знаменатель второго числа до знаменателя первого числа
		num2.numerator *= num1.denominator / num2.denominator;
	}
	else if (n2.denominator % num1.denominator == 0) {							// если знаменатель второго числа делится нацело на знаменатель первого
		num1.denominator *= num2.denominator / num1.denominator;				// домножаем знаменатель первого числа до знаменателя второго числа
		num1.numerator *= num2.denominator / num1.denominator;
	}
	else if (n2.denominator % num1.denominator != 0) {							// если знаменатель первого числа не равен знаменателю второго числа
		int buffer = num1.denominator;											// перемножаем знаменатели друг на друга, домножая числители
		num1.numerator *= num2.denominator;
		num1.denominator *= num2.denominator;
		num2.numerator *= buffer;
		num2.denominator *= buffer;
	}
	result.numerator = num1.numerator - num2.numerator;							// вычитаются числители
	result.denominator = num1.denominator;										// знаменатель является одним и тем же
	result.reduce();															// сокращение полученной дроби
	return result;
}

CommonFraction CommonFraction::mul_frac(const CommonFraction& n2) const	{		// умножение дробей
	CommonFraction result;
	result.numerator = this->numerator * n2.numerator;							// перемножаются числители дробей
	result.denominator = this->denominator * n2.denominator;					// перемножаются знаменатели дробей
	result.reduce();															// сокращение полученной дроби
	return result;
}

CommonFraction CommonFraction::div_frac(const CommonFraction& n2) const {		// деление дробей
	CommonFraction divider, result;
	int buffer;
	divider = n2;																// создаётся перевёрнутая дробь
	if (divider.numerator != 0) {												// если числитель знаменателя не равен нулю
		buffer = divider.numerator;												// закидывается в буфер значение её числителя
		divider.numerator = divider.denominator;								// переворачивается дробь
		divider.denominator = buffer;
		result.numerator = this->numerator * divider.numerator;					// перемножаются числители дробей
		result.denominator = this->denominator * divider.denominator;			// перемножаются знаменатели дробей
		result.reduce();														// сокращение дробей
		return result;
	}
	else if (divider.numerator == 0) {											// если он равен нулю, то делить нельзя
		throw logic_error("Числитель делителя равен нулю!");					// выбрасывается исключение
	}
}

double CommonFraction::decimal_frac() const {									// возвращение десятичной формы дроби
	return (double)this->numerator / (double)this->denominator;
}

string CommonFraction::string_frac() const {									// возвращение строки из обыкновенной дроби
	ostringstream str1, str2;
	str1 << this->numerator;													// занести в одну переменную числитель
	str2 << this->denominator;													// занести в другую переменную знаменатель
	return str1.str() + "/" + str2.str();										// вернуть строку
}

void CommonFraction::frac_to_file(const std::string& name_file) {				// вывод полей объекта в файл
	ofstream out(name_file);													// открытие файла для записи
	out << this->get_num() << " " << this->get_dnom();							// запись параметров через пробел
	out.close();																// закрытие файла
}

CommonFraction CommonFraction::frac_from_file(const std::string& name_file) {	// вывод полей объекта из файла
	ifstream in(name_file);														// открытие файла для чтения
	string buff;																// буферная строка
	in >> buff;																	// прочитать числитель из файла
	this->set_num(atof(buff.c_str()));											// записать числитель в объект
	in >> buff;																	// прочитать знаменатель из файла
	this->set_dnom(atof(buff.c_str()));											// записать знаменатель в объект
	in.close();																	// закрытие файла
	return *this;																// возврат изменённого объекта
}