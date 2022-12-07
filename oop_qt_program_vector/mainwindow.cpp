#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "header_vector.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_create_clicked()             // Заполнение и вывод массива
{
    lnt = ui->edit_lnt->text().toInt();                                 // Присвоить переменной lnt значение размера массива
    rng = ui->edit_rng->text().toInt();                                 // Присвоить переменной rng значение диапазона значений
    array.clear();                                                      // Очистить текущий массив
    kib::random_vec(array, lnt, rng);                                   // Заполнить массив случайными значениями
    ui->list_output->appendPlainText("Создан массив размера L = "
                  + QString::number(lnt) + " и диапазона R = "          // Обращение к пользователю
                  + QString::number(rng));
    for (unsigned i = 0; i < array.size(); i++) {
        ui->list_output->appendPlainText("a[" + QString::number(i) + "] = "
                                         + QString::number(array[i]));          // Вывести массив в столбик
    }
}

void MainWindow::on_button_sum_clicked()            // Вычисление и вывод суммы
{
    sum = kib::sum(array);              // Присвоить значение суммы
    ui->list_output->appendPlainText("Сумма элементов текущего массива: "   // Вывести сумму элементов
                                     + QString::number(sum));
}

void MainWindow::on_author_triggered()          // Справка о разработчике
{
    QMessageBox::about(this, "О разработчике...", "Кибирев Михаил ВМК-20");     // О разработчике
}

void MainWindow::on_action_save_triggered()      // Сохранение в файл
{
    kib::output_file(array);                                                // Вывести массив в файл
    ui->list_output->appendPlainText("Массив успешно загружен в файл");     // Сообщить об этом
}

void MainWindow::on_active_load_triggered()         // Вывод из файла
{
    kib::input_file(array);                                                 // Вывести массив из файла
    ui->list_output->appendPlainText("Массив успешно выгружен из файла");   // Сообщить о выводе
    for (unsigned i = 0; i < array.size(); i++) {
        ui->list_output->appendPlainText("a[" + QString::number(i) + "] = "
                                         + QString::number(array[i]));          // Вывести массив в столбик
    }
}

