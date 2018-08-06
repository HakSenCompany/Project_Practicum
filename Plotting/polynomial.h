#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <QString>
#include <regex>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Polynomial
{
public:
    Polynomial();
    int* getCoeffecient(QString input);
    int firstCoeffcient(QString input);
    int countX(QString input);
    int getConstant(QString input);
    int *getPower(QString input);

    void linear(QString input, Ui::MainWindow *ui);
    void Quatratic(QString input, Ui::MainWindow *ui);
    void polyFunction(QString input, Ui::MainWindow *ui);

private:

};

#endif // POLYNOMIAL_H
