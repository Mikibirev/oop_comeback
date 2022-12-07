/* ---------------------------------
-- Студент:         Кибирев М.Г.  --
-- Преподаватель:   Ветров С.В.   --
--------------------------------- */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <string>
#include <sstream>

#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // слот обработки входящего числа
    void processing_numerals();
    // слот обработки входящего оператора
    void processing_operations();
    // слот обработки тригонометрических функций
    void processing_trigonometry();

    // ввод левой скобки
    void on_b_left_clicked();
    // ввод правой скобки
    void on_b_right_clicked();
    // ввод плавающей точки
    void on_b_point_clicked();
    // ввод унарного минуса
    void on_b_uminus_clicked();

    // вычисление выражения
    void on_b_equals_clicked();
    // очистка выражения
    void on_b_clear_clicked();
    // стереть один символ из выражения
    void on_b_back_clicked();

    // вывод информации об авторе
    void on_action_about_author_triggered();

private:
    Ui::MainWindow *ui;

    // строка с инфиксным выражением
    std::string infix;
    // буфер для хранения вставляемого символа
    QPushButton* buffer;
    // последний символ
    char ultimate;
    // предпоследний символ
    char penultimate;
    // строка удаления
    QString erase_buf;
    // класс калькулятора
    Calculator main_calc;
    // флаг наличия точки
    short flag_point;

};
#endif // MAINWINDOW_H
