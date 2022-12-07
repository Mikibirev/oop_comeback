// написано Кибиревым Михаилом из ВМК-20-1
#include <iostream>
#include "Student.h"

Student::Student():Human() {				// конструктор по умолчанию
	num_record = 0;							// нулевой номер зачётной книжки
	num_course = 0;							// нулевой номер курса
	group = "-";							// никакая группа
	status = "-";							// никакой статус
}

Student::Student(const std::string& f, const std::string& s, const std::string& m, const int& a, const int& n_r, const int& n_c, const std::string& g, const std::string& st):Human(f, s, m, a) {
	set_num_rec(n_r);						// сеттер номера зачётки
	set_num_crs(n_c);						// сеттер номера курса
	set_grp(g);								// сеттер названия группы
	set_stat(st);							// сеттер статуса студента
}

void Student::set_num_rec(const int& n_r) {		// сеттер номера зачётки
	if ((n_r > 100000) && (n_r < 999999)) {		// если номер шестизначный,
		num_record = n_r;						// тогда записываем
	}
	else {
		throw std::logic_error("Неверный формат номера!");
	}
}

void Student::set_num_crs(const int& n_c) {		// сеттер номера курса
	if ((n_c < 5) && (n_c > 0)) {				// если с первого курса по четвёртый,
		num_course = n_c;						// тогда записываем
	}
	else {
		throw std::logic_error("Неправильный номер курса!");
	}
}

void Student::set_nums(const int& n_r, const int& n_c) {	// совмещённый сеттер
	set_num_rec(n_r);
	set_num_crs(n_c);
}

void Student::set_grp(const std::string& g) {				// сеттер группы
	if (!g.empty()) {										// если строка не пустая,
		group = g;											// тогда записываем
	}
	else {
		throw std::logic_error("Пустая строка группы!");
	}
}

void Student::set_stat(const std::string& st) {			// сеттер статуса
	if (!st.empty()) {									// если строка не пустая,
		status = st;									// тогда записываем
	}
	else {
		throw std::logic_error("Пустая строка статуса!");
	}
}

int Student::get_num_rec() const {				// возврат номера зачётки
	return num_record;
};

int Student::get_num_crs() const {				// возврат номера курса
	return num_course;
}

std::string Student::get_grp() const {			// возврат названия группы
	return group;
}

std::string Student::get_stat() const {			// возврат статуса
	return status;
}

void Student::add_crs(const int& v) {								// прибавить курс, если не выходит за пределы
	if ((num_course + v < 5) && (num_course + v > 0)) {
		num_course += v;
	}
	else {
		throw std::logic_error("Выход за границы учебного плана при сложении!");
	}
}

void Student::sub_crs(const int& v) {
	if ((num_course - v < 5) && (num_course - v > 0)) {				// вычесть курс, если не выходит за пределы
		num_course -= v;
	}
	else {
		throw std::logic_error("Выход за границы учебного плана при вычитании!");
	}
}

std::string Student::get_string() const {		// формирование строки с данными через абзац

	std::string full = "Имя: " + Human::get_name() + "\n"
		+ "Фамилия: " + Human::get_surn() + "\n"
		+ "Отчество: " + Human::get_midn() + "\n"
		+ "Возраст: " + std::to_string(Human::get_age()) + "\n"
		+ "Номер зачётки: " + std::to_string(num_record) + "\n"
		+ "Номер курса: " + std::to_string(num_course) + "\n"
		+ "Группа: " + group + "\n"
		+ "Статус: " + status;
	return full;
}