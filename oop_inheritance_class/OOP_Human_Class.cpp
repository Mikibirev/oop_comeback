// написано Кибиревым Михаилом из ВМК-20-1
#include <iostream>
#include "Human.h"
#include "Student.h"
#include "Lecturer.h"
using namespace std;

int main() {
    setlocale(0, "");                                                                               // русская локализация    
    try {                                                                                           // ловим исключения:
        Human Father("Геннадий", "Кибирев", "Николаевич", 57);                                      // в классе Human
        Student Me("Михаил", "Кибирев", "Геннадьевич", 19, 454228, 2, "ВМК-20", "Обучается");       // в классе student
        Lecturer Mother("Марина", "Кибирева", "Петровна", 50, "МГУ", 888);                          // в классе lecturer
    }
    catch (logic_error err)                                                                         // если поймали исключение:
    {
        cout << "Обнаружена ошибка: " << err.what() << endl;                                        // вывод сути исключения
        system("pause");                                                                            // фиксация консоли
        return 0;                                                                                   // закрытие программы
    }
        
    Human* father = new Human("Геннадий", "Кибирев", "Николаевич", 57);
    Student* me = new Student("Михаил", "Кибирев", "Геннадьевич", 19, 454228, 2, "ВМК-20", "Обучается");
    Lecturer* mother = new Lecturer("Марина", "Кибирева", "Петровна", 50, "МГУ", 888);

    father->add_age(5);                                                     // проверка прибавления к возрасту
    father->sub_age(3);                                                     // проверка вычитания из возраста
    
    me->add_crs(2);                                                         // проверка увеличения курса
    me->sub_crs(1);                                                         // проверка уменьшения курса

    mother->acd_dgr_up();                                                   // проверка увеличения учёной степени до кандидата
    mother->acd_dgr_up();                                                   // проверка увеличения учёной степени до доктора

    cout << "Мой папа:\n" << father->get_string() << endl << endl;          // вывод получившегося объекта Human
    cout << "Моя мама:\n" << mother->get_string() << endl << endl;          // вывод получившегося объекта Student
    cout << "Я:\n" << me->get_string() << endl << endl;                     // вывод получившегося объекта Lecturer

    delete father;                                                          // очитка памяти от Human
    delete mother;                                                          // очитка памяти от Student
    delete me;                                                              // очитка памяти от Lecturer

    system("pause");                                                        // фиксация консоли
    return 0;                                                               // закрытие программы
}