#ifndef MATRIX_H
#define MATRIX_H

#include <QException>
#include <QDebug>
#include "vector.h"

using namespace std;

class MyMatrix
{
private:
    MyVector *vec;
    size_t m, n;

public:
    // Вспомогательная функция копирования массива
    void copyM(const MyVector * from, MyVector * to, const size_t ii, const size_t jj);
    MyMatrix();
    MyMatrix(size_t count, int flag);
    MyMatrix(size_t i, size_t j, int flag);
    ~MyMatrix();
    MyMatrix(const MyMatrix& m);
    MyVector &operator[](int ind1);
    MyVector operator[](int ind1) const;
    friend MyMatrix submatrix(int ind1, int ind2, MyMatrix mm);
    friend void transposition(MyMatrix &a);
    friend class test_matrix;
    //Присваивания
    MyMatrix &operator=(const MyMatrix &m);
};

#endif // MATRIX_H
