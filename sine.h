#ifndef SINE_H
#define SINE_H
#include <QString>
#include <ui_mainwindow.h>

class Sine
{
public:
    Sine();
    int getFirstCoefficient(QString input);
    QString getPoly(QString input);
    void sinePoly(QString input, Ui::MainWindow *ui);
};

#endif // SINE_H
