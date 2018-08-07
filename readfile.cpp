#include "readfile.h"
#include<QDebug>
#include<iostream>
#include<QAxObject>
#include<iostream>
ReadFIle::ReadFIle()
{
    ddata=new double[12];
    catigory=new QString[12];
    sdata=new QString[10];
}
void ReadFIle::openFile(const QString& fileName )
{
    QAxObject* excel = new QAxObject( "Excel.Application", 0 );
    QAxObject* workbooks = excel->querySubObject( "Workbooks" );
    QAxObject* workbook = workbooks->querySubObject( "Open(const QString&)", fileName );
        QAxObject*cell;
        for (int row=1; row <=12; row++)
        {
            for (int column=1; column <=1; column++)
            {
                cell = excel->querySubObject("Cells(Int, Int)", row, column );
                QVariant val = cell->dynamicCall("value");
                catigory[row-1]=val.toString();
                qDebug()<<*(catigory+(row-1));
            }
            for (int column=2; column <=2; column++)
            {
                cell = excel->querySubObject("Cells(Int, Int)", row, column );
                QVariant val = cell->dynamicCall("value");
                 ddata[row-1]=val.toDouble();
                 qDebug()<<*(ddata+(row-1));
            }
        }
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete cell;
}

double *ReadFIle::dData()
{
    return ddata;
}

QString *ReadFIle::sString()
{
    return sdata;
}

QString *ReadFIle::Catigory()
{
    return catigory;
}

ReadFIle::~ReadFIle()
{
    delete [] catigory;
    delete [] sdata;
    delete [] ddata;
}

double ReadFIle::getMax()const
{
    double temp = ddata[0];
    for(int i =1 ;i<catigory->length();i++)
    {
        if(temp<ddata[i])
            temp = ddata[i];
    }
    return temp;
}
double ReadFIle::getMin()const
{
    double temp = ddata[0];
    for(int i =1 ;i<catigory->length();i++)
    {
        if(temp>ddata[i])
            temp = ddata[i];
    }
    return temp;
}
