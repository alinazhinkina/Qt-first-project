#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QException>
#include <iostream>
#include <QDebug>
#include "test_vector.h"
#include "test_matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  //  test_vector::run();
  //  test_matrix::run();


    cout << "Enter the dimensions of the matrix, the number of rows, then the number of columns"<<std::endl;
    size_t m,n;
    cin >> m >> n;
    cout << "If you want a unit matrix, enter 1" << std::endl;
    cout << "If you want a zero matrix, enter 0" << std::endl;
    cout << "If you want to enter a matrix, enter any number" << std::endl;
    int flag;
    cin >> flag;
    MyMatrix M(m,n,0);
    if (flag!=1 && flag!=0)
    {
     cout << "Enter the matrix" << std::endl;
    cin >> M;
    }
    if(flag==1)
        M=MyMatrix(m,n,1);

    const size_t task = 12;
        const char*menu[task] = { "Enter 1 if you want to get a sub-matrix of given sizes",
                                  "Enter 2 if you want to transpose the matrix",
                                  "Enter 3 if you want to calculate the determinant",
                                  "Enter 4 if you want to calculate the algebraic complement of the matrix",
                                  "Enter 5 if you want to get the inverse matrix",
                                  "Enter 6 if you want to multiply the matrix by a number",
                                  "Enter 7 if you want to fold the matrices",
                                  "Enter 8 if you want to subtract matrices",
                                  "Enter 9 if you want to calculate the scalar product of the matrix",
                                  "Enter 10 if you want to compare matrices",
                                  "Enter 11 if you want to enter a new first matrix",
                                  "Enter 12 if you want to quit" };
    for (int i = 0; i < task; i++)
    cout << "        " << menu[i] << endl;
    cout << "   Choose an action: " << endl;
    while (cin >> flag)
                {

    if(flag<=6)
    {
        MyMatrix M1(M.m, M.n, 1);
        switch(flag)
        {
        case 1:
            cout << "Enter the dimensions of the new matrix, the number of rows, then the number of columns"<<std::endl;
            cin >> m >> n;
            cout << "New matrix:" << std::endl << submatrix(m,n,M);
            cout << endl;
            cout << "   Choose an action: " << endl;
            break;
        case 2:
            transposition(M);
           cout << "The transposed matrix:" << std::endl << M;
           cout << endl;
           cout << "   Choose an action: " << endl;
            break;
        case 3:
            cout << "The matrix determinant:" << std::endl << determinant(M, M.m);
            cout << endl;
            cout << "   Choose an action: " << endl;
            break;
        case 4:
            cout << "Enter the indexes of the element: the number of rows, then the number of columns"<<std::endl;
            cin >> m >> n;
            cout << "The algebraic complement of the matrix:" << std::endl << cofactor(M,m,n);
            cout << endl;
            cout << "   Choose an action: " << endl;
            break;
        case 5:
            M1 = inverse(M);
            cout << "Inverse matrix:" << std::endl << M1 << endl;
            cout << "Let's check"<< endl;
            if (check(M, M1) == true)
                qDebug() << "RIGHT";
            else
                qDebug() << "WRONG";
            cout << endl;
            cout << "   Choose an action: " << endl;
            break;
        case 6:
            cout << "Enter the number" << std::endl;
            cin >> flag;
            cout << "New matrix:" << std::endl << M * flag;
            cout << endl;
            cout << "   Choose an action: " << endl;
            break;
    }}
        else
        {
             cout << "Enter the second matrix" << std::endl;
             cout << "Enter the dimensions of the matrix, the number of columns, then the number of rows" << std::endl;
           cin >> m >> n;
            cout << "If you want an identity matrix, enter 1" << std::endl;
           cout  << "If you want a zero matrix, enter 0" << std::endl;
            cout << "If you want to enter a matrix, enter any number" << std::endl;
            int buff;
            cin >> buff;
            MyMatrix A(m,n,buff);
            switch(flag)
            {
            case 7:
              cout << "A new matrix obtained by the complexity:" << std::endl << M+A;
              cout << endl;
              cout << "   Choose an action: " << endl;
                break;
            case 8:
               cout << "A new matrix obtained by subtraction:" << std::endl << M-A;
               cout << endl;
               cout << "   Choose an action: " << endl;
                break;
            case 9:
                cout << "Scalar product:" << std::endl << M*A;
                cout << endl;
                cout << "   Choose an action: " << endl;
                break;
            case 10:
                if (M == A)
                cout << "The first matrix is equal" << std::endl;
                else
                cout << "The second matrix is unequal" << std::endl;
                cout << endl;
                cout << "   Choose an action: " << endl;
                break;
            case 11:
                cout << "Enter the matrix" << std::endl;
                cin>>M;
                cout << endl;
                cout << "   Choose an action: " << endl;
                break;
            case 12:
                break;
                            default:
                                for (int i = 0; i < task; i++)
                                    cout << "        " << menu[i] << endl;
                                cout << "    Choose an action: " << endl;
                                break;
        }
        }}


 //   MyMatrix mat1(3,1);


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

 /*
    mat1[0][0] = 1;
    mat1[0][1] = 0;
    mat1[0][2] = 2;
    mat1[1][0] = 0;
    mat1[1][1] = 3;
    mat1[1][2] = 1;
    mat1[2][0] = 1;
    mat1[2][1] = 1;
    mat1[2][2] = 1;
                        */


/*    mat1[0][0] = 3;
    mat1[0][1] = 5;
    mat1[0][2] = 8;
    mat1[1][0] = 4;
    mat1[1][1] = 9;
    mat1[1][2] = 0;
    mat1[2][0] = 2;
    mat1[2][1] = 1;
    mat1[2][2] = 7;
    cout << mat1;*/
  //  MyVector v(3,1);
  //  MyVector v2 = mat1 * v;

  //  cout << v2;
  //     for (int i = 0; i<3; ++i)
   //     qDebug() << v2[i];

/*
     MyMatrix mat2(3,1);
     MyMatrix mat3(3,1);
     mat3 = mat1 * mat2;
     cout << mat3;          */


/*     mat2 = inverse(mat1);
     if (check(mat1, mat2) == true)
         qDebug() << "RIGHT";
     else
         qDebug() << "WRONG";*/
//   cout << inverse(mat1);
    return a.exec();
}
