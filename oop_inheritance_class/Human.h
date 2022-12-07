// �������� ��������� �������� �� ���-20-1
#pragma once
#include <iostream>
#include <string>

class Human {
private:
	std::string firstname;					// ��� ��������
	std::string surname;					// ������� ��������
	std::string middlename;					// �������� �������
	int age;								// ������� ��������
public:
	Human();								// ����������� �� ���������
	Human(const std::string& f, const std::string& s, const std::string& m, const int& a);		// ���������� � ��������� �������
	void set_name(const std::string& f);	// ���� �����
	void set_surn(const std::string& s);	// ���� �������
	void set_midn(const std::string& m);	// ���� ��������
	void set_fuln(const std::string& f, const std::string& s, const std::string& m);		// ���� ���������
	void set_age(const int& a);				// ���� ��������
	std::string get_name() const;			// ������� �����
	std::string get_surn() const;			// ������� �������
	std::string get_midn() const;			// ������� ��������
	int get_age() const;					// ������� ��������
	void add_age(const int& v);				// ���������� ��������
	void sub_age(const int& v);				// ���������� ��������
	virtual std::string get_string() const;	// ������� ������ � �������

	// todo ����� ����� virtual

};