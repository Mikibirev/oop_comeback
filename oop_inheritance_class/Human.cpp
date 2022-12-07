// �������� ��������� �������� �� ���-20-1
#include <iostream>
#include "Human.h"

Human::Human() {								// ����������� �� ���������
	firstname = "-";							// ���������� ����� �� ���������
	surname = "-";								// ���������� ������� �� ���������
	middlename = "-";							// ���������� �������� �� ���������
	age = 0;									// ������� ������� - �������� �� ����������
}

Human::Human(const std::string& f, const std::string& s, const std::string& m, const int& a) {		// ���������� � �������� �������
	set_name(f);								// ������ ��� �����
	set_surn(s);								// ������ ��� �������
	set_midn(m);								// ������ ��� ��������
	set_age(a);									// ������ ��� ��������
}

void Human::set_name(const std::string& f) {	// ������ ��� �����
	if (!f.empty()) {							// ���� ������ ����� �� ������,
		firstname = f;							// ����� ��� �������������
	}
	else {
		throw std::logic_error("������ ������ �����!");
	}
}

void Human::set_surn(const std::string& s) {	// ������ ��� �������
	if (!s.empty()) {							// ���� ������ ������� �� ������,
		surname = s;							// ����� ������� �������������
	}
	else {
		throw std::logic_error("������ ������ �������!");
	}
}

void Human::set_midn(const std::string& m) {	// ������ ��� ��������
	if (!m.empty()) {							// ���� ������ �������� �� ������,
		middlename = m;							// ����� �������� �������������
	}
	else {
		throw std::logic_error("������ ������ ��������!");
	}
}

void Human::set_fuln(const std::string& f, const std::string& s, const std::string& m) {		// ������ ��� ���������
	set_name(f);								// ������ ��� �����
	set_surn(s);								// ������ ��� ��������
	set_midn(m);								// ������ ��� ��������
}

void Human::set_age(const int& a) {				// ������ ��� ��������
	if ((a >= 0) && (a < 100)) {				// ���� ������� � ��������� 0-100,
		age = a;								// ����� ������� �������������
	}
	else {
		throw std::logic_error("������� �� ������������� ����������!");
	}
};

std::string Human::get_name() const {				// ������� �����
	return firstname;
};

std::string Human::get_surn() const {				// ������� �������
	return surname;
};

std::string Human::get_midn() const {				// ������� ��������
	return middlename;
};

int Human::get_age() const {						// ������� ��������
	return age;
};

void Human::add_age(const int& v) {					// ����������� � ��������
	if ((age + v > 0) && (age + v < 100)) {			// ���� ����������� �� ����� �� �������� 0-100,
		age += v;									// ����� ����������
	}
	else {
		throw std::logic_error("����������� ������� �� ������� �������������� ��������!");
	}
};

void Human::sub_age(const int& v) {					// ��������� �� ��������
	if ((age - v > 0) && (age - v < 100)) {			// ���� ��������� �� ����� �� �������� 0-100,
		age -= v;									// ����� ��������
	}
	else {
		throw std::logic_error("��������� ������� �� ������� �������������� ��������!");
	}
};

std::string Human::get_string() const {				// ������������ ������ � ������� ����� �����

	std::string full = "���: " + firstname + "\n"
		+ "�������: " + surname + "\n" 
		+ "��������: " + middlename + "\n"
		+ "�������: " + std::to_string(age);
	return full;
};