#include "cosine.h"
#include "polynomial.h"
#include "sine.h"
Cosine::Cosine()
{

}

int Cosine::getFirstCoefficient(QString input)
{
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 'c')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 'c')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

void Cosine::cosPoly(QString input, Ui::MainWindow *ui)
{
    Polynomial poly;
    Sine sin;
    double y = 0;
    double x = 0;
    QVector<double> X(401), Y(401);
    while(x<=400){
        X[x] = x/8 - 25;
        for(int i=0; i<poly.countX(input); i++){
            y += (double)poly.getCoeffecient(sin.getPoly(input))[i] * pow(X[x], (double)poly.getPower(sin.getPoly(input))[i]);
        }
        y += poly.getConstant(sin.getPoly(input));
        Y[x] = this->getFirstCoefficient(input) * cos(y);
        y = 0;
        x++;
    }

    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::red,2));
    ui->plot->graph(0)->setData(X,Y);
    ui->plot->replot();
}

