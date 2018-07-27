#include "polynomial.h"
#include <QDebug>
Polynomial::Polynomial()
{

}

int Polynomial::firstCoeffcient(QString input){
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 'x')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 'x')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

int Polynomial::countX(QString input){
    int x = 0;
    for(int i=0; i<input.length(); i++){
        if(input[i] == 'x'){
            x++;
            continue;
        }
    }
    return x;
}

int Polynomial::getConstant(QString input){
    int i;
    std::string constant = "";
    std::string Input = input.toStdString();
    for(i=input.length(); i>0; i--){
        if(input[i] == '+' || input[i] == '-'){
            break;
        }
    }
    for(int j=i; j<input.length(); j++){
        if(input[i] == 'x'){
            constant = "0";
        }else
            constant = constant + Input[j];
    }
    int con = atoi(constant.c_str());
    return con;
}

int *Polynomial::getPower(QString input)
{
    std::string A = "";
    int *p = new int[10];
    for (int u=0; u<10; u++){
        p[u] = 1;
    }
    std::string inputed = input.toStdString();
    int pos = this->countX(input);
    int i, j=0, k, l;
    for(k=0; k<pos; k++){
        for(i=j; i<input.length(); i++){
            if(input[i] == 'x'){
                if(input[i+1] == '^'){
                    for(l=i+2; l<input.length(); l++){
                        if(input[l] == '+' || input[l] == '-' || input[l] == NULL){
                            break;
                        }
                        for(int z=i+2; z<l; z++){
                            A = A + inputed[z];
                        }
                    }
                }
                else{
                    A = "1";
                }
            }
        }
        p[k] = atoi(A.c_str());
    }
}

int *Polynomial::getCoeffecient(QString input){
    std::string A = "";
    int *p = new int[10];
    for (int u=0; u<10; u++){
        p[u] = 0;
    }
    p[0] = Polynomial::firstCoeffcient(input);
    std::string inputed = input.toStdString();
    int i, j=0, k, l, o=0;
    int pos = Polynomial::countX(input);
    for(k=1; k<=pos; k++){
        for(i=j; i<input.length(); i++){
            if(input[i] == '+' || input[i] == '-'){
                //qDebug()<<i;
                j = i+1;
                break;
            }
        }
        for(l=i; l<input.length(); l++){
            if(input[l] == 'x'){
                //qDebug()<<l;
                o = l+1;
                break;
            }
        }
        for(int f=i; f<l; f++){
            A = A + inputed[f];
        }
        p[k] = atoi(A.c_str());
        A = "";
    }
    return p;
}


