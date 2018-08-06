#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsWidget>
#include "polynomial.h"
#include "sine.h"
#include "cosine.h"
#include "logarithm.h"
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

void MainWindow::on_lineEdit_returnPressed()
{
    Polynomial poly;
    Sine sin;
    Cosine cos;
    Logarithm log;

    QString input = ui->lineEdit->text();
    std::string inputed = input.toStdString();
    std::regex polynomial("([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?");
    std::regex sine("([-]|[+])?([0-9]?[0-9])?sin[(]([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?[)]");
    std::regex cosine("([-]|[+])?([0-9]?[0-9])?cos[(]([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?[)]");
    std::regex logarithm("([-]|[+])?([0-9]?[0-9])?log[(]([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?[)]");
    bool match_poly = regex_match(inputed, polynomial);
    bool match_sine = regex_match(inputed, sine);
    bool match_cosine = regex_match(inputed, cosine);
    bool match_log = regex_match(inputed, logarithm);


    if(match_poly){
        poly.polyFunction(input,ui);
    }else if(match_sine){
        sin.sinePoly(input, ui);
    }else if(match_cosine){
        cos.cosPoly(input, ui);
    }else if(match_log){
        log.logPoly(input, ui);
    }

}
