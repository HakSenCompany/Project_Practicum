#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsWidget>
#include "polynomial.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->customPlot->xAxis->setRange(-15, 15);
    ui->customPlot->yAxis->setRange(-10, 10);
    ui->customPlot->axisRect()->setupFullAxesBox();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::linear(QString input){
    Polynomial polynomial;

    double x = 0;
    QVector<double>X(201), Y(201);
    while(x<=200){
        X[x] = x/4-25;
        Y[x] = polynomial.firstCoeffcient(input)*X[x] + polynomial.getConstant(input);
        x++;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::red,2));
    ui->customPlot->graph(0)->setData(X,Y);
    ui->customPlot->replot();
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString input = ui->lineEdit->text();
    std::string inputed = input.toStdString();
    std::regex linear("[-]?([0-9]?[0-9])?x(([+]|[-])([0-9]?[0-9]))?");
    bool match_linear = regex_match(inputed, linear);
    if(match_linear){
        MainWindow::linear(input);
    }
    Polynomial poly;
    qDebug()<<poly.getPower(input)[0];
    qDebug()<<poly.getPower(input)[1];

}
