// c������ ��������� �������� �� ���-20
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "CommonFraction.h"
using namespace std;

CommonFraction::CommonFraction() {												// ����������� �� ���������
	set_num(0);																	// ��������� ����� ����
	set_dnom(1);																// ����������� �� ����� ����
}

CommonFraction::CommonFraction(const int& numr, const int& dnomr) {				// ����������� �� ���������
	set_num(numr);																// ���������
	set_dnom(dnomr);															// �����������
}

void CommonFraction::set_frac(const int& numr, const int& dnomr) {				// ������ ����� ���������
	set_num(numr);																// ���������
	set_dnom(dnomr);															// �����������
	return;
}

void CommonFraction::set_num(const int& numr) {									// ������ ���������
	numerator = numr;
	return;
}

void CommonFraction::set_dnom(const int& dnomr) {								// ������ �����������
	if (dnomr != 0) {															// ���� ����������� �� ����� ����
		denominator = dnomr;													// �������� �����������
		return;
	}
	else {																		// ���� ����������� ����� ����
		throw logic_error("����������� ����� ����!");							// �������� ����������
	}
}

int CommonFraction::get_num() const {											// ������� ���������
	return numerator;
}

int CommonFraction::get_dnom() const {											// ������� �����������
	return denominator;
}

void CommonFraction::reduce() {													// ��������� �����
	for (int i = denominator; i > 0; i--) {										// ������������ � ������� �������� ����������� �����������
		if (numerator % i == 0) {												// ���� ��������� ������� �� ����������� �����������
			if (denominator % i == 0) {											// ����������� ������� �� ���� ���� �����������
				numerator /= i;													// ������ ��������� �� ������� �����
				denominator /= i;												// ������ ����������� �� ������� �����
			}
		}
	}
	return;
}

CommonFraction CommonFraction::return_more(const CommonFraction& n2) const {	// ������� ������� ��� ������
	double buf, buf_2;
	buf = (double)this->numerator / (double)this->denominator;					// ��������� � ���������� ����� ����� �1
	buf_2 = (double)n2.numerator / (double)n2.denominator;						// ��������� � ���������� ����� ����� �2
	if (buf >= buf_2) {															// ���� ������ ����� ������ ��� ����� �������
		return *this;															// ������� ������ �����
	}
	else {																		// ���� ������ ����� ������ ��� ����� �������
		return n2;																// ������� ������ �����
	}
}

CommonFraction CommonFraction::return_less(const CommonFraction& n2) const {	// ������� ������� ��� ������
	double buf, buf_2;
	buf = (double)this->numerator / (double)this->denominator;					// ��������� � ���������� ����� ����� �1
	buf_2 = (double)n2.numerator / (double)n2.denominator;						// ��������� � ���������� ����� ����� �2
	if (buf <= buf_2) {															// ���� ������ ����� ������ ��� ����� �������
		return *this;															// ������� ������ �����
	}
	else {																		// ���� ������ ����� ������ ��� ����� �������
		return n2;																// ������� ������ �����
	}
}

CommonFraction CommonFraction::add_frac(const CommonFraction& n2) const {		// ������� ������������ �����
	CommonFraction num1 = *this, num2 = n2, result;
	if (num1.denominator % num2.denominator == 0) {								// ���� ����������� ������� ����� ������� ������ �� ����������� �������
		num2.denominator *= num1.denominator / num2.denominator;				// ��������� ����������� ������� ����� �� ����������� ������� �����
		num2.numerator *= num1.denominator / num2.denominator;
	}
	else if (n2.denominator % num1.denominator == 0) {							// ���� ����������� ������� ����� ������� ������ �� ����������� �������
		num1.denominator *= num2.denominator / num1.denominator;				// ��������� ����������� ������� ����� �� ����������� ������� �����
		num1.numerator *= num2.denominator / num1.denominator;
	}
	else if (n2.denominator % num1.denominator != 0) {							// ���� ����������� ������� ����� �� ����� ����������� ������� �����
		int buffer = num1.denominator;											// ����������� ����������� ���� �� �����, �������� ���������
		num1.numerator *= num2.denominator;
		num1.denominator *= num2.denominator;
		num2.numerator *= buffer;
		num2.denominator *= buffer;
	}
	result.numerator = num1.numerator + num2.numerator;							// ������������ ���������
	result.denominator = num1.denominator;										// ����������� �������� ����� � ��� ��
	result.reduce();															// ���������� ���������� �����
	return result;
}

CommonFraction CommonFraction::sub_frac(const CommonFraction& n2) const {		// ������� ������������ �����
	CommonFraction num1 = *this, num2 = n2, result;
	if (num1.denominator % num2.denominator == 0) {								// ���� ����������� ������� ����� ������� ������ �� ����������� �������
		num2.denominator *= num1.denominator / num2.denominator;				// ��������� ����������� ������� ����� �� ����������� ������� �����
		num2.numerator *= num1.denominator / num2.denominator;
	}
	else if (n2.denominator % num1.denominator == 0) {							// ���� ����������� ������� ����� ������� ������ �� ����������� �������
		num1.denominator *= num2.denominator / num1.denominator;				// ��������� ����������� ������� ����� �� ����������� ������� �����
		num1.numerator *= num2.denominator / num1.denominator;
	}
	else if (n2.denominator % num1.denominator != 0) {							// ���� ����������� ������� ����� �� ����� ����������� ������� �����
		int buffer = num1.denominator;											// ����������� ����������� ���� �� �����, �������� ���������
		num1.numerator *= num2.denominator;
		num1.denominator *= num2.denominator;
		num2.numerator *= buffer;
		num2.denominator *= buffer;
	}
	result.numerator = num1.numerator - num2.numerator;							// ���������� ���������
	result.denominator = num1.denominator;										// ����������� �������� ����� � ��� ��
	result.reduce();															// ���������� ���������� �����
	return result;
}

CommonFraction CommonFraction::mul_frac(const CommonFraction& n2) const	{		// ��������� ������
	CommonFraction result;
	result.numerator = this->numerator * n2.numerator;							// ������������� ��������� ������
	result.denominator = this->denominator * n2.denominator;					// ������������� ����������� ������
	result.reduce();															// ���������� ���������� �����
	return result;
}

CommonFraction CommonFraction::div_frac(const CommonFraction& n2) const {		// ������� ������
	CommonFraction divider, result;
	int buffer;
	divider = n2;																// �������� ����������� �����
	if (divider.numerator != 0) {												// ���� ��������� ����������� �� ����� ����
		buffer = divider.numerator;												// ������������ � ����� �������� � ���������
		divider.numerator = divider.denominator;								// ���������������� �����
		divider.denominator = buffer;
		result.numerator = this->numerator * divider.numerator;					// ������������� ��������� ������
		result.denominator = this->denominator * divider.denominator;			// ������������� ����������� ������
		result.reduce();														// ���������� ������
		return result;
	}
	else if (divider.numerator == 0) {											// ���� �� ����� ����, �� ������ ������
		throw logic_error("��������� �������� ����� ����!");					// ������������� ����������
	}
}

double CommonFraction::decimal_frac() const {									// ����������� ���������� ����� �����
	return (double)this->numerator / (double)this->denominator;
}

string CommonFraction::string_frac() const {									// ����������� ������ �� ������������ �����
	ostringstream str1, str2;
	str1 << this->numerator;													// ������� � ���� ���������� ���������
	str2 << this->denominator;													// ������� � ������ ���������� �����������
	return str1.str() + "/" + str2.str();										// ������� ������
}

void CommonFraction::frac_to_file(const std::string& name_file) {				// ����� ����� ������� � ����
	ofstream out(name_file);													// �������� ����� ��� ������
	out << this->get_num() << " " << this->get_dnom();							// ������ ���������� ����� ������
	out.close();																// �������� �����
}

CommonFraction CommonFraction::frac_from_file(const std::string& name_file) {	// ����� ����� ������� �� �����
	ifstream in(name_file);														// �������� ����� ��� ������
	string buff;																// �������� ������
	in >> buff;																	// ��������� ��������� �� �����
	this->set_num(atof(buff.c_str()));											// �������� ��������� � ������
	in >> buff;																	// ��������� ����������� �� �����
	this->set_dnom(atof(buff.c_str()));											// �������� ����������� � ������
	in.close();																	// �������� �����
	return *this;																// ������� ���������� �������
}