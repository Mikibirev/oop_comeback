// сделано Кибиревым Михаилом из ВМК-20
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class CommonFraction {												// класс обыкновенной дроби
private:
	int numerator;													// числитель дроби
	int denominator;												// знаменатель дроби
public:
	CommonFraction();												// конструктор по умолчанию
	CommonFraction(const int& numr, const int& dnomr);				// констуктор с входными данными
	void set_frac(const int& numr, const int& dnomr);				// запись обыкновенной дроби
	void set_num(const int& numr);									// запись числителя
	void set_dnom(const int& dnomr);								// запись знаменателя
	int get_num() const;											// возвращение числителя
	int get_dnom() const;											// возвращение знаменателя
	void reduce();													// сокращение дроби
	CommonFraction return_more(const CommonFraction& n2) const;		// вернуть большее или равное
	CommonFraction return_less(const CommonFraction& n2) const;		// вернуть меньшее или равное
	CommonFraction add_frac(const CommonFraction& n2) const;		// сложить дроби
	CommonFraction sub_frac(const CommonFraction& n2) const;		// вычесть дроби
	CommonFraction mul_frac(const CommonFraction& n2) const;		// умножить дроби
	CommonFraction div_frac(const CommonFraction& n2) const;		// разделить дроби
	double decimal_frac() const;									// вернуть десятичное
	string string_frac() const;										// вернуть строку

	void frac_to_file(const string& name_file);						// вывод в файл
	CommonFraction frac_from_file(const string& name_file);			// вывод из файла
};