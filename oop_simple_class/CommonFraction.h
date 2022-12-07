// ������� ��������� �������� �� ���-20
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class CommonFraction {												// ����� ������������ �����
private:
	int numerator;													// ��������� �����
	int denominator;												// ����������� �����
public:
	CommonFraction();												// ����������� �� ���������
	CommonFraction(const int& numr, const int& dnomr);				// ���������� � �������� �������
	void set_frac(const int& numr, const int& dnomr);				// ������ ������������ �����
	void set_num(const int& numr);									// ������ ���������
	void set_dnom(const int& dnomr);								// ������ �����������
	int get_num() const;											// ����������� ���������
	int get_dnom() const;											// ����������� �����������
	void reduce();													// ���������� �����
	CommonFraction return_more(const CommonFraction& n2) const;		// ������� ������� ��� ������
	CommonFraction return_less(const CommonFraction& n2) const;		// ������� ������� ��� ������
	CommonFraction add_frac(const CommonFraction& n2) const;		// ������� �����
	CommonFraction sub_frac(const CommonFraction& n2) const;		// ������� �����
	CommonFraction mul_frac(const CommonFraction& n2) const;		// �������� �����
	CommonFraction div_frac(const CommonFraction& n2) const;		// ��������� �����
	double decimal_frac() const;									// ������� ����������
	string string_frac() const;										// ������� ������

	void frac_to_file(const string& name_file);						// ����� � ����
	CommonFraction frac_from_file(const string& name_file);			// ����� �� �����
};