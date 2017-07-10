#ifndef MATRIX_H
#define MATRIX_H

#include <QException>
#include <QDebug>
#include <ostream>
#include "vector.h"

using namespace std;

class MyMatrix
{
public:
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
    MyVector get_vec();
    //Сложения матриц
    MyMatrix &operator+(const MyMatrix m);
    //Вычитания матриц
    MyMatrix &operator-(const MyMatrix m);
    //Умножения матрицы на число
    MyMatrix &operator*(double k);
    //Умножения матрицы на вектор
    MyVector &operator*(MyVector &v);
    //Умножения матрицы на матрицу
    MyMatrix &operator*(MyMatrix &mat);
    friend MyMatrix submatrix(int ind1, int ind2, MyMatrix &mm);
    friend void transposition(MyMatrix &a);
    friend class test_matrix;
    //Присваивания
    MyMatrix &operator=(const MyMatrix &m);
    friend bool operator==(MyMatrix &m1, MyMatrix &m2);
    friend bool operator!=(MyMatrix &m1, MyMatrix &m2);
    friend double determinant(MyMatrix &a, size_t z);
    friend void delete_column(MyMatrix &a, size_t m, size_t n);
    friend double cofactor(MyMatrix &a, size_t m, size_t n);
    friend MyMatrix inverse(MyMatrix &a);
    friend bool check(MyMatrix &m1, MyMatrix &m2);
};
std::ostream &operator<<(std::ostream &os, const MyMatrix &m);
QTextStream &operator<<(QTextStream &os, const MyMatrix &m);
std::istream &operator>>(std::istream &is, MyMatrix &m);
QTextStream &operator>>(QTextStream &is, MyMatrix &m);
#endif // MATRIX_H
