#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_button_create_clicked();

    void on_button_sum_clicked();

    void on_author_triggered();

    void on_action_save_triggered();

    void on_active_load_triggered();

private:
    Ui::MainWindow *ui;
    QVector<int> array;     // Массив
    int lnt, rng;           // Входные данные
    int sum;                // Выходные данные

};
#endif // MAINWINDOW_H
