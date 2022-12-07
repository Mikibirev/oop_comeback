/* ---------------------------------
-- Студент:         Кибирев М.Г.  --
-- Преподаватель:   Ветров С.В.   --
--------------------------------- */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    infix = "0";
    ui->setupUi(this);
    ui->input->setText("0");
    ui->output->setText("");

    // ----- цифры
    connect(ui->b_0,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_1,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_2,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_3,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_4,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_5,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_6,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_7,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_8,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    connect(ui->b_9,        SIGNAL(clicked()), this, SLOT(processing_numerals()));
    // ----- арифметика
    connect(ui->b_plus,     SIGNAL(clicked()), this, SLOT(processing_operations()));
    connect(ui->b_minus,    SIGNAL(clicked()), this, SLOT(processing_operations()));
    connect(ui->b_multiple, SIGNAL(clicked()), this, SLOT(processing_operations()));
    connect(ui->b_division, SIGNAL(clicked()), this, SLOT(processing_operations()));
    connect(ui->b_power,    SIGNAL(clicked()), this, SLOT(processing_operations()));
    // ----- тригонометрия
    connect(ui->b_sin,      SIGNAL(clicked()), this, SLOT(processing_trigonometry()));
    connect(ui->b_cos,      SIGNAL(clicked()), this, SLOT(processing_trigonometry()));
    connect(ui->b_tan,      SIGNAL(clicked()), this, SLOT(processing_trigonometry()));
    connect(ui->b_ctg,      SIGNAL(clicked()), this, SLOT(processing_trigonometry()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processing_numerals()
{
    buffer = (QPushButton *)sender();
    ultimate = infix.substr(infix.size() - 1, 1)[0];
    // если в выражении больше одного символа и последний символ = 0
    if (infix.size() > 1 && ultimate == '0')
    {
        // если до нуля что-то было, значит это продолжение полноценного числа
        penultimate = infix.substr(infix.size() - 2, 1)[0];
        if ((penultimate >= '0' && penultimate <= '9') || penultimate == '.')
        {
            // просто добавляем цифру в строку
            ui->input->setText(ui->input->text() + buffer->text());
            infix += buffer->text().toStdString();
        }
        // если до нуля ничего не было, значит это не число, а просто ноль
        else
        {
            // прежде добавления удаляем этот ноль
            erase_buf = ui->input->text();
            erase_buf.chop(1);
            ui->input->setText(erase_buf + buffer->text());
            infix.erase(infix.size() - 1, 1);
            infix += buffer->text().toStdString();
        }
    }
    // если в строке только ноль
    else if (infix.size() == 1 && ultimate == '0')
    {
        // заменяем этот ноль числом
        ui->input->setText(buffer->text());
        infix.erase(infix.size() - 1, 1);
        infix += buffer->text().toStdString();
    }
    // во всех остальных случаях
    else
    {
        // добавляем цифру к строке
        ui->input->setText(ui->input->text() + buffer->text());
        infix += buffer->text().toStdString();
    }
}

void MainWindow::processing_operations()
{
    buffer = (QPushButton *)sender();
    ultimate = infix.substr(infix.size() - 1, 1)[0];
    // если перед вставляемой операцией есть число
    if (ultimate >= '0' && ultimate <= '9')
    {
        // тогда просто добавляем операцию
        ui->input->setText(ui->input->text() + buffer->text());
        infix += buffer->text().toStdString();
    }
    // если скобка
    else if (ultimate == ')')
    {
        ui->input->setText(ui->input->text() + buffer->text());
        infix += buffer->text().toStdString();
    }
    // если числа нет
    else if (!(ultimate >= '0' && ultimate <= '9') || ultimate == '.' || ultimate == '(')
    {
        erase_buf = ui->input->text();
        erase_buf.chop(1);
        ui->input->setText(erase_buf + buffer->text());
        infix.erase(infix.size() - 1, 1);
        infix += buffer->text().toStdString();
    }
}

void MainWindow::processing_trigonometry()
{
    buffer = (QPushButton *)sender();
    ultimate = infix.substr(infix.size() - 1, 1)[0];
    // если перед функцией стоит число
    if (infix.size() == 1 && ultimate == '0')
    {
        ui->input->setText(buffer->text() + "(");
        if (buffer->text().toStdString() == "ctg")
            infix = buffer->text().toStdString().substr(2, 1) + "(";
        else
            infix = buffer->text().toStdString().substr(0, 1) + "(";
    }
    else if (ultimate >= '0' && ultimate <= '9')
    {
        // умножаем это число на функцию
        ui->input->setText(ui->input->text() + "*" + buffer->text() + "(");
        if (buffer->text().toStdString() == "ctg")
            infix += "*" + buffer->text().toStdString().substr(2, 1) + "(";
        else
            infix += "*" + buffer->text().toStdString().substr(0, 1) + "(";
    }
    // если перед функцией стоит запятая
    else if (ultimate == '.')
    {
        // удалить эту запятую перед вставкой функции
        erase_buf = ui->input->text();
        erase_buf.chop(1);
        ui->input->setText(erase_buf + "*" + buffer->text() + "(");
        infix.erase(infix.size() - 1, 1);
        if (buffer->text().toStdString() == "ctg")
            infix += "*" + buffer->text().toStdString().substr(2, 1) + "(";
        else
            infix += "*" + buffer->text().toStdString().substr(0, 1) + "(";
    }
    else if (ultimate == ')')
    {
        ui->input->setText(ui->input->text() + "*" + buffer->text() + "(");
        if (buffer->text().toStdString() == "ctg")
            infix += "*" + buffer->text().toStdString().substr(2, 1) + "(";
        else
            infix += "*" + buffer->text().toStdString().substr(0, 1) + "(";
    }
    // во всех остальных случаях просто вставить
    else
    {
        ui->input->setText(ui->input->text() + buffer->text() + "(");
        if (buffer->text().toStdString() == "ctg")
            infix += buffer->text().toStdString().substr(2, 1) + "(";
        else
            infix += buffer->text().toStdString().substr(0, 1) + "(";
    }
}

// ----- добавить плавающую точку
void MainWindow::on_b_point_clicked()
{
    // убедиться, что в числе нет второй точки
    flag_point = 0;
    for (unsigned i = 1; i <= infix.size(); i++)
    {
        // если достигнуто начало выражения и ничего не найдено, тогда добавить точку
        if (infix.size() == i && flag_point == 0)
        {
            ui->input->setText(ui->input->text() + ".");
            infix += ".";
            break;
        }
        ultimate = infix.substr(infix.size() - i, 1)[0];
        switch (ultimate)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case '~':
            // если найдена операция, не найдена точка, не найдено число, тогда добавить ноль и точку
            if (flag_point == 0 && i == 1)
            {
                ui->input->setText(ui->input->text() + "0.");
                infix += "0.";
                flag_point = -1;
            }
            // если найдена операция, не найдена точка, но найдено число, тогда добавить точку
            else if (flag_point == 0 && i > 1)
            {
                ui->input->setText(ui->input->text() + ".");
                infix += ".";
                flag_point = -1;
            }
            // если ничего не найдено, надо вырубить метод
            else
                flag_point = -1;
            break;
        case '.':
            // если найдена точка, тогда гг, вырубаем метод
            flag_point = 1;
            break;
        default:
            break;
        }
        // если точка найдена, тогда ничего не делать
        if (flag_point == -1)
            break;
    }
}

// ----- добавить левую скобку
// --
// --
void MainWindow::on_b_left_clicked()
{
    ultimate = infix.substr(infix.size() - 1, 1)[0];
    if (infix.size() == 1 && ultimate == '0')
    {
        ui->input->setText("(");
        infix = "(";
    }
    else if ((ultimate >= '0' && ultimate <= '9') || ultimate == ')')
    {
        // умножаем это число на функцию
        ui->input->setText(ui->input->text() + "*(");
        infix += "*(";
    }
    // если перед скобкой стоит запятая
    else if (ultimate == '.')
    {
        // удалить эту запятую перед вставкой скобки
        erase_buf = ui->input->text();
        erase_buf.chop(1);
        ui->input->setText(erase_buf + "*(");
        infix.erase(infix.size() - 1, 1);
        infix += "*(";
    }
    // во всех остальных случаях просто вставить
    else
    {
        ui->input->setText(ui->input->text() + "(");
        infix += "(";
    }
}

// ----- добавить правую скобку
// --
// --
void MainWindow::on_b_right_clicked()
{
    ultimate = infix.substr(infix.size() - 1, 1)[0];
    if ((ultimate >= '0' && ultimate <= '9') || ultimate == ')')
    {
        // просто добавляем скобку
        ui->input->setText(ui->input->text() + ")");
        infix += ")";
    }
    // если перед скобкой стоит запятая
    else if (ultimate == '.')
    {
        // удалить эту запятую перед вставкой скобки
        erase_buf = ui->input->text();
        erase_buf.chop(1);
        ui->input->setText(erase_buf + ")");
        infix.erase(infix.size() - 1, 1);
        infix += ")";
    }
}

// ----- вставка унарного минуса
// --
// --
void MainWindow::on_b_uminus_clicked()
{
    buffer = (QPushButton *)sender();
    ultimate = infix.substr(infix.size() - 1, 1)[0];

    // если последний символ является числом
    if ((ultimate >= '0' && ultimate <= '9') || ultimate == '.')
    {
        // проходим строку в поисках начала числа
        for (unsigned i = 1; i <= infix.size(); i++)
        {
            penultimate = infix.substr(infix.size() - i, 1)[0];
            // как только найдено начало числа
            if (!((penultimate >= '0' && penultimate <= '9')) || penultimate == '.' || i == infix.size())
            {
                // если унарный минус у числа уже есть, тогда удаляем этот минус
                if (penultimate == '~')
                {
                    erase_buf = ui->input->text();
                    erase_buf.remove(erase_buf.size() - i, 1);
                    ui->input->setText(erase_buf);
                    infix.erase(infix.size() - i, 1);
                }
                // если унарного минуса нет, тогда добавляем этот минус
                else
                {
                    i--;
                    erase_buf = ui->input->text();
                    erase_buf.insert(erase_buf.size() - i, '-');
                    ui->input->setText(erase_buf);
                    infix.insert(infix.size() - i, "~");
                }
                break;
            }
        }
    }
}

// ----- вычислить выражение
// --
// --
void MainWindow::on_b_equals_clicked()
{
    std::stringstream result_buf;
    ultimate = infix.substr(infix.size() - 1, 1)[0];

    // если последний символ не является числом
    if (!(ultimate >= '0' && ultimate <= '9') || ultimate == '.')
    {
        // и не является скобкой, тогда удаляем символ с конца
        if (ultimate != ')' && ultimate != '(')
        {
            erase_buf = ui->input->text();
            erase_buf.chop(1);
            ui->input->setText(erase_buf);
            infix.erase(infix.size() - 1, 1);
        }
    }

    // ----- ловим исключение в случае какой-нибудь *****
    try
    {
        // вывести результат в output
        result_buf << main_calc.Calculate(infix);
        ui->output->setText("=" + QString::fromStdString(result_buf.str()));
        ui->statusbar->showMessage(infix.c_str());
        main_calc.Clear();
    }
    catch (std::invalid_argument& err)
    {
        // восстановить калькулятор, если поймано исключение
        ui->output->setText("ERROR");
        ui->statusbar->showMessage(err.what());
        main_calc.Clear();
    }
}

// ----- очистить выражение
// --
// --
void MainWindow::on_b_clear_clicked()
{
    ui->input->setText("0");
    ui->output->clear();
    ui->statusbar->clearMessage();
    infix = "0";
}

// ----- стереть один символ
void MainWindow::on_b_back_clicked()
{
    // если размер выражения равен одному, тогда обнуляем всё
    if (infix.size() == 1)
    {
        ui->input->setText("0");
        ui->output->clear();
        ui->statusbar->clearMessage();
        infix = "0";
    }
    // если размер больше единицы, тогда удаляем один символ
    else
    {
        switch (infix.substr(infix.size() - 1, 1)[0])
        {
        // для тригонометрических функций нужно удалить 1 символ из строки и 3 символа из окна
        case 's':
        case 'c':
        case 't':
        case 'g':
            erase_buf = ui->input->text();
            erase_buf.chop(3);
            ui->input->setText(erase_buf);
            infix.erase(infix.size() - 1, 1);
            break;
        // для всего остального спокойно удаляем по одному символу из строки и окна
        default:
            erase_buf = ui->input->text();
            erase_buf.chop(1);
            ui->input->setText(erase_buf);
            infix.erase(infix.size() - 1, 1);
            break;
        }
    }
}

// ----- вывод сообщения об авторе калькулятора
// --
// --
void MainWindow::on_action_about_author_triggered()
{
    ui->statusbar->showMessage("Author: Kibirev Mikhail");
}

