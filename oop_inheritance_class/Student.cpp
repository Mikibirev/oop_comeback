// �������� ��������� �������� �� ���-20-1
#include <iostream>
#include "Student.h"

Student::Student():Human() {				// ����������� �� ���������
	num_record = 0;							// ������� ����� �������� ������
	num_course = 0;							// ������� ����� �����
	group = "-";							// ������� ������
	status = "-";							// ������� ������
}

Student::Student(const std::string& f, const std::string& s, const std::string& m, const int& a, const int& n_r, const int& n_c, const std::string& g, const std::string& st):Human(f, s, m, a) {
	set_num_rec(n_r);						// ������ ������ �������
	set_num_crs(n_c);						// ������ ������ �����
	set_grp(g);								// ������ �������� ������
	set_stat(st);							// ������ ������� ��������
}

void Student::set_num_rec(const int& n_r) {		// ������ ������ �������
	if ((n_r > 100000) && (n_r < 999999)) {		// ���� ����� ������������,
		num_record = n_r;						// ����� ����������
	}
	else {
		throw std::logic_error("�������� ������ ������!");
	}
}

void Student::set_num_crs(const int& n_c) {		// ������ ������ �����
	if ((n_c < 5) && (n_c > 0)) {				// ���� � ������� ����� �� ��������,
		num_course = n_c;						// ����� ����������
	}
	else {
		throw std::logic_error("������������ ����� �����!");
	}
}

void Student::set_nums(const int& n_r, const int& n_c) {	// ����������� ������
	set_num_rec(n_r);
	set_num_crs(n_c);
}

void Student::set_grp(const std::string& g) {				// ������ ������
	if (!g.empty()) {										// ���� ������ �� ������,
		group = g;											// ����� ����������
	}
	else {
		throw std::logic_error("������ ������ ������!");
	}
}

void Student::set_stat(const std::string& st) {			// ������ �������
	if (!st.empty()) {									// ���� ������ �� ������,
		status = st;									// ����� ����������
	}
	else {
		throw std::logic_error("������ ������ �������!");
	}
}

int Student::get_num_rec() const {				// ������� ������ �������
	return num_record;
};

int Student::get_num_crs() const {				// ������� ������ �����
	return num_course;
}

std::string Student::get_grp() const {			// ������� �������� ������
	return group;
}

std::string Student::get_stat() const {			// ������� �������
	return status;
}

void Student::add_crs(const int& v) {								// ��������� ����, ���� �� ������� �� �������
	if ((num_course + v < 5) && (num_course + v > 0)) {
		num_course += v;
	}
	else {
		throw std::logic_error("����� �� ������� �������� ����� ��� ��������!");
	}
}

void Student::sub_crs(const int& v) {
	if ((num_course - v < 5) && (num_course - v > 0)) {				// ������� ����, ���� �� ������� �� �������
		num_course -= v;
	}
	else {
		throw std::logic_error("����� �� ������� �������� ����� ��� ���������!");
	}
}

std::string Student::get_string() const {		// ������������ ������ � ������� ����� �����

	std::string full = "���: " + Human::get_name() + "\n"
		+ "�������: " + Human::get_surn() + "\n"
		+ "��������: " + Human::get_midn() + "\n"
		+ "�������: " + std::to_string(Human::get_age()) + "\n"
		+ "����� �������: " + std::to_string(num_record) + "\n"
		+ "����� �����: " + std::to_string(num_course) + "\n"
		+ "������: " + group + "\n"
		+ "������: " + status;
	return full;
}