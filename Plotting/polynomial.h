#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <QString>
#include <regex>
#include <string>
#include "mainwindow.h"

class Polynomial
{
public:
    Polynomial();
    int* getCoeffecient(QString input);
    int firstCoeffcient(QString input);
    int countX(QString input);
    int getConstant(QString input);
    int *getPower(QString input);
private:

};

#endif // POLYNOMIAL_H
