#ifndef VECTOR_H
#define VECTOR_H
using namespace std;
#include <QException>
#include <QDebug>

class vector1
{

public:
    int *data;
    size_t size;

public:
    //Конструктор вектора по размеру(пустой вектор), нужен для корректной работы программы
    vector1(size_t size);
    //Конструктор пустого вектора
    vector1();
    //Конструктор для единичного или нулевого вектора
    vector1(size_t size, int flag);
    //Деструктор
    ~vector1();
    //Конструктор копии
     vector1(const vector1& v);

    //Метод вычисления нормы
    double norma();
    //Перегрузки операторов:
    //Доступа к элементам
    int &operator[](int index);
    int operator[](int index) const;
    //Вычитания векторов
    vector1 &operator-(const vector1 v);
    //Сложения векторов
    vector1 &operator+(const vector1 v);
    //Скалярного произведения векторов
    double operator*(const vector1 &v);
    //Умножения вектора на число
    vector1 &operator*(double k);

    //Вспомогательная функция для конструктора копии
     void copy(const int * from, int * to, size_t size);

    friend class test_vector;
    friend class matrix1;
};

#endif // VECTOR_H
