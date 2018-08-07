#ifndef COSINE_H
#define COSINE_H
#include <QString>
#include "ui_mainwindow.h"

class Cosine
{
public:
    Cosine();
    int getFirstCoefficient(QString input);
    void cosPoly(QString input, Ui::MainWindow *ui);
};

#endif // COSINE_H
