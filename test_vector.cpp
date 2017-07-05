#include "test_vector.h"

const double precision=0.000134;
//Тест для конструктора
bool test_vector::construct()
{
    //Конструкторы для нулевых и единичных векторов
    size_t n = 5;
    MyVector d(n,1);
    for(int i=0; i<n;++i)
        assert(d[i]==1);
    MyVector d1(n,0);
    for(int i=0; i<n;++i)
        assert(d1[i]==0);
    //Неверно дан флаг
    try {
        MyVector d2(1,5);

        assert(0);
    }
    catch (char *s) {
        assert(1);
    }
    //Отрицательный размер
    try {
        MyVector d3(-1,1);
        assert(0);
    }
    catch (const runtime_error &e) {
        assert(1);
    }

#ifdef _DEBUG
    std::cerr << "test vector constructor: OK" << std::endl;
#endif
    return true;
}

//Тест для конструктора копии
bool test_vector::copy()
{
    size_t n = 5;
    MyVector d(n,1);
    for (int i = 0; i < n; ++i)
        d[i] = rand();
    MyVector d1(n,1);
    d.copy(d.data, d1.data, n);

    for (int i = 0; i < n; ++i) {
        assert(d[i] == d1[i]);
    }

#ifdef _DEBUG
    std::cerr << "test vector copy: OK" << std::endl;
#endif
    return true;
}

//Тест для метода вычисления нормы вектора
bool test_vector::norma() {
    size_t n = 4;
    MyVector d(n,1);
    assert(abs(d.norma() - 4)<precision);

#ifdef _DEBUG
    std::cerr << "test vector norma: OK" << std::endl;
#endif
    return true;
}

//Тест для оператора +
bool test_vector::plus() {

    //Векторы одной длины
    size_t n = 3;
    MyVector d(n,1);
    d[0] = 1;
    d[1] = 2;
    d[2] = 3;
    MyVector d2(n,1);
    d2[0] = 1;
    d2[1] = 2;
    d2[2] = 3;
    MyVector v = d + d2;
    MyVector v0(n,1);
    v0[0] = 2;
    v0[1] = 4;
    v0[2] = 6;
    for(int i=0; i<n; ++i)
    assert(v[i] == v0[i]);
    //размеры отличаются

    try {
        MyVector d3(1,1);
        v = d + d3;
        assert(0);
    }
    catch (const runtime_error &e) {
        assert(1);
    }


#ifdef _DEBUG
    std::cerr << "test vector operator plus: OK" << std::endl;
#endif
    return true;
}

//Тест для оператора -
bool test_vector::minus() {

    //Векторы одной длины
    size_t n = 3;
    MyVector d(n,1);
    d[0] = 1;
    d[1] = 2;
    d[2] = 3;
    MyVector d2(n,1);
    d2[0] = 1;
    d2[1] = 2;
    d2[2] = 3;
    MyVector v = d - d2;
    MyVector v0(n,1);
    v0[0] = 0;
    v0[1] = 0;
    v0[2] = 0;
    for(int i=0; i<n; ++i)
    assert(v[i] == v0[i]);
    //размеры отличаются

    try {
        MyVector d3(1,1);
        v = d - d3;
        assert(0);
    }
    catch (const runtime_error &e) {
        assert(1);
    }


#ifdef _DEBUG
    std::cerr << "test vector operator minus: OK" << std::endl;
#endif
    return true;
}

//Тест для оператора скалярного произведения
bool test_vector::umn() {

    //Векторы одной длины
    size_t n = 3;
    MyVector d(n,1);
    MyVector d2(n,1);
    double v = d * d2;
    assert(v == 3);
    //размеры отличаются

    try {
        MyVector d3(1,1);
        v = d * d3;
        assert(0);
    }
    catch (const runtime_error &e) {
        assert(1);
    }


#ifdef _DEBUG
    std::cerr << "test vector operator skal: OK" << std::endl;
#endif
    return true;
}

//Тест для оператора умножения вектора на число
bool test_vector::umnk() {

    size_t n = 3;
    MyVector d(n);
    d[0] = 1;
    d[1] = 1;
    d[2] = 1;
    MyVector d2(n);
    d2[0] = 3;
    d2[1] = 3;
    d2[2] = 3;
    MyVector v = d * 3;
    for(int i=0; i<n; ++i)
    assert(v[i] == d2[i]);


#ifdef _DEBUG
    std::cerr << "test vector operator *k: OK" << std::endl;
#endif
    return true;
}

//Запуск тестов
bool test_vector::run()
{
    test_vector test;
    return test.construct() && test.copy() && test.norma() &&test.plus() && test.minus() && test.umn() && test.umnk();
}
