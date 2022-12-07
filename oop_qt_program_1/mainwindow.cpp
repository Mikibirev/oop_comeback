#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "header_period.h"
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

void MainWindow::on_button_calc_clicked()
{
    lnt = ui->edit_input->text().toDouble();                                // Присвоить переменной lnt значение длины
    prd = kib::period_l(lnt);                                               // Посчитать период и присвоить переменной prd
    ui->label_output->setText(QString::number(prd));                        // Вывести результат в отдельное окно
    ui->list_output->appendPlainText("При L = " + QString::number(lnt)
                                     + ", T = " + QString::number(prd));    // Вывести результат в отчёт list
}

void MainWindow::on_button_rand_clicked()
{
    ui->edit_input->setText(QString::number(rand() % 100));     // Выбрать случайное значение
}


void MainWindow::on_author_triggered()
{
    QMessageBox::about(this, "О разработчике...", "Кибирев Михаил ВМК-20");     // О разработчике
}

