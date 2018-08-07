#ifndef VISUALIZATION_H
#define VISUALIZATION_H
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtWidgets/QGridLayout>
#include"readfile.h"
QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

class Visualization:public QWidget
{
    Q_OBJECT
public:
   explicit  Visualization(QWidget *parent=0);
    void createChart(int index);
    void openFile(const QString& fileName);
    void setTheme(int);
private:
   QChart *createBarChart() const;
   QChart *createPiChart()const;
   QChart *createScatterChart()const;
   QChart *createAreaChart()const;
   QChart *createSlineChart()const;
   QChart *createLineChart()const;
private:
    QGridLayout *layout;
    QChartView*view;
    ReadFIle file;
private:
    QString *sdata;
    double  *ddata;
    QString *catigory;
};

#endif // VISUALIZATION_H
