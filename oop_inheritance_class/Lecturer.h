// �������� ��������� �������� �� ���-20-1
#pragma once
#include <iostream>
#include <string>
#include "Human.h"

class Lecturer : public Human {
private:
	std::string academic_degree;					// ������� �������
	std::string name_university;					// �������� ������������
	int num_lec_hall;								// ����� ���������
public:
	Lecturer();
	Lecturer(const std::string& f, const std::string& s, const std::string& m, const int& a, const std::string& n_u, const int& n_lh);

	void set_univ(const std::string& n_u);			// ���� ������������
	void set_lec_h(const int& n_ln);				// ���� ������ ���������
	void acd_dgr_up();								// ���������� ����� ������� �������
	std::string get_acd_dgr() const;				// ������� ������ �������
	std::string get_univ() const;					// ������� ������������
	int get_lec_h() const;							// ������� ������ ���������
	std::string get_string() const;					// ������� ������ � �������
};