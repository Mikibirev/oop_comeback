// написано Кибиревым Михаилом из ВМК-20-1
#include <iostream>
#include "Human.h"

Human::Human() {								// конструктор по умолчанию
	firstname = "-";							// отсутствие имени по умолчанию
	surname = "-";								// отсутствие фамилии по умолчанию
	middlename = "-";							// отсутствие отчества по умолчанию
	age = 0;									// нулевой возраст - человека не существует
}

Human::Human(const std::string& f, const std::string& s, const std::string& m, const int& a) {		// констуктор с входными данными
	set_name(f);								// сеттер для имени
	set_surn(s);								// сеттер для фамилии
	set_midn(m);								// сеттер для отчества
	set_age(a);									// сеттер для возраста
}

void Human::set_name(const std::string& f) {	// сеттер для имени
	if (!f.empty()) {							// если строка имени не пустая,
		firstname = f;							// тогда имя присваивается
	}
	else {
		throw std::logic_error("Пустая строка имени!");
	}
}

void Human::set_surn(const std::string& s) {	// сеттер для фамилии
	if (!s.empty()) {							// если строка фамилии не пустая,
		surname = s;							// тогда фамилия присваивается
	}
	else {
		throw std::logic_error("Пустая строка фамилии!");
	}
}

void Human::set_midn(const std::string& m) {	// сеттер для отчества
	if (!m.empty()) {							// если строка отчества не пустая,
		middlename = m;							// тогда отчество присваивается
	}
	else {
		throw std::logic_error("Пустая строка отчества!");
	}
}

void Human::set_fuln(const std::string& f, const std::string& s, const std::string& m) {		// сеттер для инициалов
	set_name(f);								// сеттер для имени
	set_surn(s);								// сеттер для фамилияя
	set_midn(m);								// сеттер для отчества
}

void Human::set_age(const int& a) {				// сеттер для возраста
	if ((a >= 0) && (a < 100)) {				// если возраст в диапазоне 0-100,
		age = a;								// тогда возраст присваивается
	}
	else {
		throw std::logic_error("Возраст не соответствует реальности!");
	}
};

std::string Human::get_name() const {				// возврат имени
	return firstname;
};

std::string Human::get_surn() const {				// возврат фамилии
	return surname;
};

std::string Human::get_midn() const {				// возврат отчества
	return middlename;
};

int Human::get_age() const {						// возврат возраста
	return age;
};

void Human::add_age(const int& v) {					// прибавление к возрасту
	if ((age + v > 0) && (age + v < 100)) {			// если прибавление не зайдёт за диапазон 0-100,
		age += v;									// тогда прибавляем
	}
	else {
		throw std::logic_error("Прибавление выходит за границы теоретического возраста!");
	}
};

void Human::sub_age(const int& v) {					// вычитание из возраста
	if ((age - v > 0) && (age - v < 100)) {			// если вычитание не зайдёт за диапазон 0-100,
		age -= v;									// тогда вычитаем
	}
	else {
		throw std::logic_error("Вычитание выходит за границы теоретического возраста!");
	}
};

std::string Human::get_string() const {				// формирование строки с данными через абзац

	std::string full = "Имя: " + firstname + "\n"
		+ "Фамилия: " + surname + "\n" 
		+ "Отчество: " + middlename + "\n"
		+ "Возраст: " + std::to_string(age);
	return full;
};