// написано Кибиревым Михаилом из ВМК-20-1
#pragma once
#include <iostream>
#include <string>

class Human {
private:
	std::string firstname;					// имя человека
	std::string surname;					// фамилия человека
	std::string middlename;					// отчество человеа
	int age;								// возраст человека
public:
	Human();								// конструктор по умолчанию
	Human(const std::string& f, const std::string& s, const std::string& m, const int& a);		// констуктор с входящими данными
	void set_name(const std::string& f);	// ввод имени
	void set_surn(const std::string& s);	// ввод фамилии
	void set_midn(const std::string& m);	// ввод отчества
	void set_fuln(const std::string& f, const std::string& s, const std::string& m);		// ввод инициалов
	void set_age(const int& a);				// ввод возраста
	std::string get_name() const;			// возврат имени
	std::string get_surn() const;			// возврат фамилии
	std::string get_midn() const;			// возврат отчества
	int get_age() const;					// возврат возраста
	void add_age(const int& v);				// увеличение возраста
	void sub_age(const int& v);				// уменьшение возраста
	virtual std::string get_string() const;	// возврат строки с данными

	// todo Зачем нужен virtual

};