// написано Кибиревым Михаилом из ВМК-20-1
#pragma once
#include <iostream>
#include <string>
#include "Human.h"

class Student: public Human {					// класс Student с наследованием от класса Human 
private:
	int num_record;								// номер зачётной книжки студента
	int num_course;								// номер курса студента
	std::string group;							// название группы студента
	std::string status;							// текущий статус студента
public:
	Student();
	Student(const std::string& f, const std::string& s, const std::string& m, const int& a, const int& n_r, const int& n_c, const std::string& g, const std::string& st);

	void set_num_rec(const int& n_r);					// ввод номера зачётной книжки
	void set_num_crs(const int& n_c);					// ввод номера курса
	void set_nums(const int& r, const int& c);			// ввод номеров зачётки и курса
	void set_grp(const std::string& g);					// ввод названия группы
	void set_stat(const std::string& st);				// ввод текущего статуса
	int get_num_rec() const;							// возврат номера зачётки
	int get_num_crs() const;							// возврат номера курса
	std::string get_grp() const;						// возврат названия группы
	std::string get_stat() const;						// возврат текущего статуса
	void add_crs(const int& v);							// прибавление курса
	void sub_crs(const int& v);							// уменьшение курса
	std::string get_string() const;						// возврат строки с данными
};