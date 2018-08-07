#ifndef LOGARITHM_H
#define LOGARITHM_H
#include <QString>
#include "ui_mainwindow.h"

class Logarithm
{
public:
    Logarithm();
    int getFirCoefficient(QString input);
    void logPoly(QString input, Ui::MainWindow *ui);
};

#endif // LOGARITHM_H
