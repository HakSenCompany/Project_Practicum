#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTimer>
#include"polynomial.h"
#include "sine.h"
#include "cosine.h"
#include "logarithm.h"
#include<regex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setFixedWidth(270);
    ui->visual->close();
    ui->comboBox->close();
    ui->comboBox_2->close();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->plot->xAxis->setRange(-15, 15);
    ui->plot->yAxis->setRange(-10, 10);
    ui->plot->axisRect()->setupFullAxesBox();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->plot->close();
    ui->visual->show();
    const QString fileName = QFileDialog::getOpenFileName(this,
      "Open file",QDir::rootPath(), "excel Files (*.xlsx *.xls *.csv)");
      if (!fileName.isEmpty())
      {
          OpenFile(fileName);
          ui->comboBox->show();
          ui->comboBox_2->show();
      }
}

void MainWindow::OpenFile(const QString &fileName)
{
     QFile file(fileName);
    ui->lineEdit->setText(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    else{
        ui->visual->openFile(fileName);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->visual->createChart(index);
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ui->visual->setTheme(index);
}


void MainWindow::on_lineEdit_2_returnPressed()
{
    ui->visual->close();
    ui->plot->show();
    Polynomial poly;
    Sine sin;
    Cosine cos;
    Logarithm log;

    QString input = ui->lineEdit_2->text();
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
