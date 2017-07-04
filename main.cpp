#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QException>
#include <iostream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*vector1 v1(5,1);
    vector1 v2(5,1);
    vector1 v=v1-v2;
    vector1 d(3,1);
    d[0] = 1;
    d[1] = 2;
    d[2] = 3;
    vector1 d2(3,1);
    d2[0] = 1;
    d2[1] = 2;
    d2[2] = 3;
    double v = d2*d;

    for(int i=0; i<3; ++i)
    qDebug() << v;*/

//    matrix1 mat(3,1);
    matrix1 m();
    return a.exec();
}
