#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QException>
#include <iostream>
#include <QDebug>
#include "test_vector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  //  test_vector::run();
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

    MyMatrix mat(3,1);
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
           qDebug() << mat[i][j];
   MyMatrix m1 = submatrix(2,2,mat);
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
           qDebug() << m1[i][j];
    return a.exec();
}
