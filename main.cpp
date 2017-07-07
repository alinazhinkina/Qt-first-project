#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QException>
#include <iostream>
#include <QDebug>
#include "test_vector.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  //  test_vector::run();
/*
    qDebug() << "Введите размеры матрицы, количество столбцов, затем количество строк" << std::endl;
    size_t m,n;
    qDebug() >> m >> n;
    qDebug() << "Если вы хотете единичную матрицу, введиет 1" << std::endl;
    qDebug() << "Если вы хотете нулевую матрицу, введиет 0" << std::endl;
    qDebug() << "Если вы хотете ввести матрицу, введите любое число" << std::endl;
    int flag;
    qDebug() >> flag;
    MyMatrix M(m,n,flag);
    const size_t task = 12;
        // выбор задания
        const char*menu[task] = { "Введите 1, если хотите получить под-матрицу заданных размеров",
            "Введите 2, если хотите транспонировать матрицу",
            "Введите 3, если хотите вычислить определитель",
            "Введите 4, если хотите вычислить алгебраическое дополнение матрицы",
            "Введите 5, если хотите получить обратную матрицу",
            "Введите 6, если хотите умножить матрицу на число",
            "Введите 7, если хотите сложить матрицы",
            "Введите 8, если хотите вычесть матрицы",
            "Введите 9, если хотите вычислить скалярное произведение матрицы",
            "Введите 10, если хотите сравнить матрицы",
            "Введите 11, если хотите ввести новую первую матрицу"
            "Введите 12, если хотите завершить работу" };
    for (int i = 0; i < task; i++)
    cout << "        " << menu[i] << endl;
    cout << "    Выберете действие: " << endl;
    while (qDebug() >> flag)
                {
    if (flag!=1 && flag!=0)
    {
    MyMatrix M(m,n,0);
    qDebug() << "Введите матрицу" << std::endl;
    qDebug() >> M;
    }


    if(flag<=6)
    {
        switch(flag)
        {
        case 1:
            qDebug() << "Введите размеры новой матрицы, количество столбцов, затем количество строк" << std::endl;
            qDebug() >> m >> n;
            qDegug() << "Новая матрица:" << std::endl << submutrix(M,m,n);
            break;
        case 2:
            qDegug() << "Транспонированная матрица:" << std::endl << transposition(M);
            break;
        case 3:
            qDegug() << "Определитель матрицы:" << std::endl << determinant(M);
            break;
        case 4:
            qDegug() << "Алгебраическое дополнение матрицы:" << std::endl << algebr(M);
            break;
        case 5:
            qDegug() << "Обратная матрица:" << std::endl << obratn(M);
            break;
        case 6:
            qDegug() << "Введите число" << std::endl;
            qDebug() >> flag;
            qDegug() << "Новая матрица:" << std::endl << umnk(M);
            break;
    }
        else
        {
            qDegug() << "Введите вторую матрицу" << std::endl;
            qDebug() << "Введите размеры матрицы, количество столбцов, затем количество строк" << std::endl;
            qDebug() >> m >> n;
            qDebug() << "Если вы хотете единичную матрицу, введиет 1" << std::endl;
            qDebug() << "Если вы хотете нулевую матрицу, введиет 0" << std::endl;
            qDebug() << "Если вы хотете ввести матрицу, введите любое число" << std::endl;
            int buff;
            qDebug() >> buff;
            MyMatrix A(m,n,buff);
            switch(flag)
            {
            case 7:
                qDegug() << "Новая матрица,полученная сложнием:" << std::endl << M+A;
                break;
            case 8:
                qDegug() << "Новая матрица,полученная вычитаением:" << std::endl << M-A;
                break;
            case 9:
                qDegug() << "Скалярное произведение:" << std::endl << M*A;
                break;
            case 10:
                if (M>A)
                qDegug() << "Первая матрица больше второй" << std::endl;
                else
                qDegug() << "Вторая матрица больше второй" << std::endl;
                break;
        }
        }
    */
    MyMatrix mat1(3,1);
    cout << mat1;
  /*  qDebug() << "mat111111111";
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
           qDebug() << mat1[i][j];
    MyMatrix mat2(3,1);
    qDebug() << "mat222222222";
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
           qDebug() << mat2[i][j];
    if (mat1 == mat2)
        qDebug() << "yeeeeees";
 MyMatrix m1 = submatrix(2,2,mat);
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
           qDebug() << m1[i][j];*/
    mat1[0][0] = 1;
    mat1[0][1] = 0;
    mat1[0][2] = 2;
    mat1[1][0] = 0;
    mat1[1][1] = 3;
    mat1[1][2] = 1;
    mat1[2][0] = 1;
    mat1[2][1] = 1;
    mat1[2][2] = 1;
    cout << mat1;
    qDebug() << determinant(mat1,3);
    cout << inverse(mat1);


//delete_column(mat1, 0, 1);

//qDebug() << "*****";
//cout << mat1 <<"eeeeeeeee";
//qDebug() << "*****";
    return a.exec();
}
