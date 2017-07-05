#ifndef VECTOR_H
#define VECTOR_H

#include <QException>
#include <QDebug>
using namespace std;
class MyVector
{

private:
    int *data;
    size_t size;

public:
    //Конструктор вектора по размеру(пустой вектор), нужен для корректной работы программы
    MyVector(size_t size);
    //Конструктор пустого вектора
    MyVector();
    //Конструктор для единичного или нулевого вектора
    MyVector(size_t size, int flag);
    //Деструктор
    ~MyVector();
    //Конструктор копии
     MyVector(const MyVector& v);

    //Метод вычисления нормы
    double norma();
    //Перегрузки операторов:
    //Доступа к элементам
    int &operator[](int index);
    int operator[](int index) const;
    //Вычитания векторов
    MyVector &operator-(const MyVector v);
    //Сложения векторов
    MyVector &operator+(const MyVector v);
    //Скалярного произведения векторов
    double operator*(const MyVector &v);
    //Умножения вектора на число
    MyVector &operator*(double k);
    //Присваивания
    MyVector &operator=(const MyVector &v);


    //Вспомогательная функция для конструктора копии
     void copy(const int * from, int * to, size_t size);

    friend class test_vector;
friend class MyMatrix;
};

#endif // VECTOR_H
