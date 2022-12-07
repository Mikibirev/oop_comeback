// написано Кибиревым Михаилом из ВМК-20-1
#include <iostream>
#include "Lecturer.h"

Lecturer::Lecturer():Human() {				// конструктор по умолчанию
	academic_degree = "-";					// нет учёной степени
	name_university = "-";					// нет университета
	num_lec_hall = 0;						// номер аудитории
}

Lecturer::Lecturer(const std::string& f, const std::string& s, const std::string& m, const int& a, const std::string& n_u, const int& n_lh):Human(f, s, m, a) {
	set_univ(n_u);							// сеттер университета
	set_lec_h(n_lh);						// сеттер аудитории
	academic_degree = "-";					// нет учёной степени
}

void Lecturer::set_univ(const std::string& n_u) {			// сеттер университета
	if (!n_u.empty()) {										// если строка не пустая,
		name_university = n_u;								// тогда записываем
	}
	else {
		throw std::logic_error("Пустая строка университета!");
	}
}

void Lecturer::set_lec_h(const int& n_lh) {			// сеттер аудитории
	if (n_lh > 0) {									// если номер больше нуля,
		num_lec_hall = n_lh;						// тогда записываем
	}
	else {
		throw std::logic_error("Неверный номер кабинета!");
	}
}

void Lecturer::acd_dgr_up() {						// присвоение учёной степени
	if (academic_degree == "-") {
		academic_degree = "Кандидат наук";			// если степени нет, то кандидат наук
	}
	else if (academic_degree == "Кандидат наук") {
		academic_degree = "Доктор наук";			// если кандидат наук, то доктор наук
	}
}

std::string Lecturer::get_acd_dgr() const {			// возврат учёной степени
	return academic_degree;
}

std::string Lecturer::get_univ() const {			// возврат университета
	return name_university;
}

int Lecturer::get_lec_h() const {					// возврат номера аудитории
	return num_lec_hall;
}

std::string Lecturer::get_string() const {			// формирование строки с данными через абзац

	std::string full = "Имя: " + Human::get_name() + "\n"
		+ "Фамилия: " + Human::get_surn() + "\n"
		+ "Отчество: " + Human::get_midn() + "\n"
		+ "Возраст: " + std::to_string(Human::get_age()) + "\n"
		+ "Учёная степень: " + academic_degree + "\n"
		+ "Университет: " + name_university + "\n"
		+ "Номер аудитории: " + std::to_string(num_lec_hall);
	return full;
}