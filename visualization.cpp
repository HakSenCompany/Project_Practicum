#include "visualization.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>
#include <QtCore/QtMath>
#include <QtGui/QImage>
#include<iostream>
#include<QDebug>
Visualization::Visualization(QWidget *parent)
    :QWidget(parent){

    layout=new QGridLayout;
    setLayout(layout);
}

QChart *Visualization::createBarChart() const
{
    QChart *chart = new QChart();

    chart->setTitle("Bar chart");
    QBarSet *set0 = new QBarSet("Jane");
    for(int i=0;i<11;i++)
    *set0 <<*(ddata+i);
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    chart->addSeries(series);
    chart->setTitle("This Barchart");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    for(int i =0;i<11;i++)
    {
        categories<<*(catigory+i);
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->axisY()->setRange(file.getMin()-3,file.getMax()+3);
    return chart;
}

QChart *Visualization::createPiChart() const
{
    QPieSeries *series = new QPieSeries();
    QPieSlice *slice;
    for(int i =0 ;i <  11 ; i++)
    {

        series->append(catigory[i]+" :"+QString::number(ddata[i]),ddata[i]);
        slice = series->slices().at(i);
        slice->setLabelVisible();
    }
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        chart->legend()->hide();
        return chart;
}

QChart *Visualization::createScatterChart() const
{
    QScatterSeries *series1 = new QScatterSeries();
    series1->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
    QStringList categories;
    for(int i =0 ; i<11 ;i++)
    {
        series1->append(i,*(ddata+i));
        categories <<*(catigory+i);
    }
    QChart*chart=new QChart;
    chart->addSeries(series1);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series1);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setDropShadowEnabled(false);
    chart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
    chart->axisY()->setRange(file.getMin()-3,file.getMax()+3);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    return chart;

}
QChart *Visualization::createSlineChart() const
{
    QSplineSeries *series = new QSplineSeries();
    series->setName("spline");
    QStringList categories;
    for(int i =0 ; i<11 ;i++)
    {
        series->append(i,*(ddata+i));
        categories <<*(catigory+i);
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Simple spline chart example");
    chart->axisY()->setRange(file.getMin()-3,file.getMax()+3);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    return chart;
}

QChart *Visualization::createLineChart() const
{
      QLineSeries *series = new QLineSeries();
      QStringList categories;
      for(int i =0 ; i<11 ;i++)
      {
          series->append(i,*(ddata+i));
          categories <<*(catigory+i);

      }
        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(series);
            QBarCategoryAxis *axisX = new QBarCategoryAxis;
            axisX->append(categories);
            chart->createDefaultAxes();
            chart->setAxisX(axisX,series);
            chart->setTitle("Simple line chart example");
            chart->axisY()->setRange(file.getMin()-3,file.getMax()+3);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            return chart;
}

void Visualization::createChart(int index)
{
    if(index==0)
    {
        layout->removeWidget(view);
        delete view;
        view = new QChartView(createPiChart());
        layout->addWidget(view);

    } else if(index==1)
    {
        layout->removeWidget(view);
        delete view;
        view = new QChartView(createBarChart());
        layout->addWidget(view);
    } else if(index==2)
    {
        layout->removeWidget(view);
        delete view;
        view = new QChartView(createScatterChart());
        layout->addWidget(view);
    }else if(index==3)
    {
        layout->removeWidget(view);
        delete view;
        view = new QChartView(createLineChart());
        layout->addWidget(view);
    }else if(index==4)
    {
        layout->removeWidget(view);
        delete view;
        view = new QChartView(createSlineChart());
        layout->addWidget(view);
    }


}
void Visualization::openFile(const QString &fileName)
{
    file.openFile(fileName);
    catigory = file.Catigory();
    ddata = file.dData();
    sdata = file.sString();
    view = new QChartView(createPiChart());
    view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    layout->addWidget(view);
}

void Visualization::setTheme(int  index)
{
    if(index==0)
        view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    else
    if(index==1)
        view->chart()->setTheme(QChart::ChartThemeLight);
    else
    if(index==2)
        view->chart()->setTheme(QChart::ChartThemeDark);
    else
     if(index==3)
        view->chart()->setTheme(QChart::ChartThemeBrownSand);
    else
     if(index==4)
        view->chart()->setTheme(QChart::ChartThemeBlueNcs);
    else
     if(index==5)
        view->chart()->setTheme(QChart::ChartThemeHighContrast);
    else
     if(index==6)
        view->chart()->setTheme(QChart::ChartThemeBlueIcy);
    else
     if(index==7)
        view->chart()->setTheme(QChart::ChartThemeQt);
}
