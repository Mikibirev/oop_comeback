// написано Кибиревым Михаилом из ВМК-20-1
#pragma once
#include <iostream>
#include <string>
#include "Human.h"

class Lecturer : public Human {
private:
	std::string academic_degree;					// учебная степень
	std::string name_university;					// название университета
	int num_lec_hall;								// номер аудитории
public:
	Lecturer();
	Lecturer(const std::string& f, const std::string& s, const std::string& m, const int& a, const std::string& n_u, const int& n_lh);

	void set_univ(const std::string& n_u);			// ввод университета
	void set_lec_h(const int& n_ln);				// ввод номера аудитории
	void acd_dgr_up();								// присвоение новой учебной степени
	std::string get_acd_dgr() const;				// возврат учёной степени
	std::string get_univ() const;					// возврат университета
	int get_lec_h() const;							// возврат номера аудитории
	std::string get_string() const;					// возврат строки с данными
};