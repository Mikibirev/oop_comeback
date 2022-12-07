// �������� ��������� �������� �� ���-20-1
#include <iostream>
#include "Lecturer.h"

Lecturer::Lecturer():Human() {				// ����������� �� ���������
	academic_degree = "-";					// ��� ������ �������
	name_university = "-";					// ��� ������������
	num_lec_hall = 0;						// ����� ���������
}

Lecturer::Lecturer(const std::string& f, const std::string& s, const std::string& m, const int& a, const std::string& n_u, const int& n_lh):Human(f, s, m, a) {
	set_univ(n_u);							// ������ ������������
	set_lec_h(n_lh);						// ������ ���������
	academic_degree = "-";					// ��� ������ �������
}

void Lecturer::set_univ(const std::string& n_u) {			// ������ ������������
	if (!n_u.empty()) {										// ���� ������ �� ������,
		name_university = n_u;								// ����� ����������
	}
	else {
		throw std::logic_error("������ ������ ������������!");
	}
}

void Lecturer::set_lec_h(const int& n_lh) {			// ������ ���������
	if (n_lh > 0) {									// ���� ����� ������ ����,
		num_lec_hall = n_lh;						// ����� ����������
	}
	else {
		throw std::logic_error("�������� ����� ��������!");
	}
}

void Lecturer::acd_dgr_up() {						// ���������� ������ �������
	if (academic_degree == "-") {
		academic_degree = "�������� ����";			// ���� ������� ���, �� �������� ����
	}
	else if (academic_degree == "�������� ����") {
		academic_degree = "������ ����";			// ���� �������� ����, �� ������ ����
	}
}

std::string Lecturer::get_acd_dgr() const {			// ������� ������ �������
	return academic_degree;
}

std::string Lecturer::get_univ() const {			// ������� ������������
	return name_university;
}

int Lecturer::get_lec_h() const {					// ������� ������ ���������
	return num_lec_hall;
}

std::string Lecturer::get_string() const {			// ������������ ������ � ������� ����� �����

	std::string full = "���: " + Human::get_name() + "\n"
		+ "�������: " + Human::get_surn() + "\n"
		+ "��������: " + Human::get_midn() + "\n"
		+ "�������: " + std::to_string(Human::get_age()) + "\n"
		+ "������ �������: " + academic_degree + "\n"
		+ "�����������: " + name_university + "\n"
		+ "����� ���������: " + std::to_string(num_lec_hall);
	return full;
}