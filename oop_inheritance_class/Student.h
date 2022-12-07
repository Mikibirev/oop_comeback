// �������� ��������� �������� �� ���-20-1
#pragma once
#include <iostream>
#include <string>
#include "Human.h"

class Student: public Human {					// ����� Student � ������������� �� ������ Human 
private:
	int num_record;								// ����� �������� ������ ��������
	int num_course;								// ����� ����� ��������
	std::string group;							// �������� ������ ��������
	std::string status;							// ������� ������ ��������
public:
	Student();
	Student(const std::string& f, const std::string& s, const std::string& m, const int& a, const int& n_r, const int& n_c, const std::string& g, const std::string& st);

	void set_num_rec(const int& n_r);					// ���� ������ �������� ������
	void set_num_crs(const int& n_c);					// ���� ������ �����
	void set_nums(const int& r, const int& c);			// ���� ������� ������� � �����
	void set_grp(const std::string& g);					// ���� �������� ������
	void set_stat(const std::string& st);				// ���� �������� �������
	int get_num_rec() const;							// ������� ������ �������
	int get_num_crs() const;							// ������� ������ �����
	std::string get_grp() const;						// ������� �������� ������
	std::string get_stat() const;						// ������� �������� �������
	void add_crs(const int& v);							// ����������� �����
	void sub_crs(const int& v);							// ���������� �����
	std::string get_string() const;						// ������� ������ � �������
};