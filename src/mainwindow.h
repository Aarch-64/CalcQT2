#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString number;
    QString operatorC;
    QString number_A;
    QString number_B;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

    void op_ce();
    void op_c();

    void num_0();
    void num_1();
    void num_2();
    void num_3();
    void num_4();
    void num_5();
    void num_6();
    void num_7();
    void num_8();
    void num_9();

    void op_mas();
    void op_menos();
    void op_multi();
    void op_div();
    void op_igual();

    void calculate(QString data);

};

#endif // MAINWINDOW_H
