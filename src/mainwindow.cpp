#include "mainwindow.h"
#include "ui/ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->show_result->setText("");

    connect(ui->boton_ce, SIGNAL(clicked(bool)), this, SLOT(op_ce()));
    connect(ui->boton_del, SIGNAL(clicked(bool)), this, SLOT(op_c()));

    connect(ui->boton_0, SIGNAL(clicked(bool)), this, SLOT(num_0()));
    connect(ui->boton_1, SIGNAL(clicked(bool)), this, SLOT(num_1()));
    connect(ui->boton_2, SIGNAL(clicked(bool)), this, SLOT(num_2()));
    connect(ui->boton_3, SIGNAL(clicked(bool)), this, SLOT(num_3()));
    connect(ui->boton_4, SIGNAL(clicked(bool)), this, SLOT(num_4()));
    connect(ui->boton_5, SIGNAL(clicked(bool)), this, SLOT(num_5()));
    connect(ui->boton_6, SIGNAL(clicked(bool)), this, SLOT(num_6()));
    connect(ui->boton_7, SIGNAL(clicked(bool)), this, SLOT(num_7()));
    connect(ui->boton_8, SIGNAL(clicked(bool)), this, SLOT(num_8()));
    connect(ui->boton_9, SIGNAL(clicked(bool)), this, SLOT(num_9()));

    connect(ui->boton_mas, SIGNAL(clicked(bool)), this, SLOT(op_mas()));
    connect(ui->boton_menos, SIGNAL(clicked(bool)), this, SLOT(op_menos()));
    connect(ui->boton_multi, SIGNAL(clicked(bool)), this, SLOT(op_multi()));
    connect(ui->boton_div, SIGNAL(clicked(bool)), this, SLOT(op_div()));
    connect(ui->boton_igual, SIGNAL(clicked(bool)), this, SLOT(op_igual()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::op_ce()
{
    number = "";
    ui->show_result->setText(number);
    ui->ui_result->setText(number);
    ui->ui_operation->setText(number);
}

void MainWindow::op_c()
{
    number = ui->show_result->text();
    ui->show_result->setText(number.remove(number.length()-1,1));
}

void MainWindow::num_0()
{
    calculate("0");
}

void MainWindow::num_1()
{
    calculate("1");
}


void MainWindow::num_2()
{
    calculate("2");
}

void MainWindow::num_3()
{
    calculate("3");
}

void MainWindow::num_4()
{
    calculate("4");
}

void MainWindow::num_5()
{
    calculate("5");
}

void MainWindow::num_6()
{
    calculate("6");
}

void MainWindow::num_7()
{
    calculate("7");
}

void MainWindow::num_8()
{
    calculate("8");
}

void MainWindow::num_9()
{
    calculate("9");
}


void MainWindow::op_mas()
{
    calculate("+");
}

void MainWindow::op_menos()
{
    calculate("-");
}

void MainWindow::op_multi()
{
    calculate("x");
}

void MainWindow::op_div()
{
    calculate("÷");
}

void MainWindow::op_igual()
{
    calculate("=");
}

void MainWindow::calculate(QString data)
{

    if(data != "=")
    {
        number = number + data;
        ui ->show_result-> setText(number);
        ui ->ui_operation-> setText(number);
        if(data == "+" || data == "-" || data == "x" || data == "÷")
            operatorC = data;
    }

    else
    {
        QString auxA = number;
        QString auxB = number;

        double num_A = 0;
        double num_B = 0;
        double result = 0;

        int pos = number.indexOf(operatorC);
        int length = number.length();

        number_A = auxA.remove(pos, length);
        number_B = auxB.remove(0,pos+1);

        num_A = number_A.toDouble();
        num_B = number_B.toDouble();



        if (operatorC == "+")  result = num_A + num_B;
        if (operatorC == "-")  result = num_A - num_B;
        if (operatorC == "÷")  result = num_A / num_B;
        if (operatorC == "x")  result = num_A * num_B;



        number = QString::number(result);

    }

     ui ->show_result-> setText(number);
     ui ->ui_result-> setText(number);


}
