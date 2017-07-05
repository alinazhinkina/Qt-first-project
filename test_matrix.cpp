#include "test_matrix.h"

const double precision=0.000134;
//Тест для конструктора
bool test_matrix::construct()
{
    //Конструкторы для нулевых и единичных векторов
    size_t n = 5;
    MyMatrix d(n,1);
    for(int i=0; i<n;++i)
        for(int j=0; j<n;++i)
        assert(d[i][j]==1);
    MyMatrix d1(n,0);
    for(int i=0; i<5;++i)
        for(int j=0; j<n;++i)
        assert(d1[i][j]==0);
    //Неверно дан флаг
    try {
        MyMatrix d2(1,5);
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }
    //Отрицательный размер
    try {
        MyMatrix d3(-1,1);
        assert(0);
    }
    catch (const runtime_error &e) {
        assert(1);
    }

#ifdef _DEBUG
    std::cerr << "test matrix constructor: OK" << std::endl;
#endif
    return true;
}

//Тест для конструктора копии
/*bool test_matrix::copy()
{
    size_t n = 5;
    MyMatrix d(n,1);
    for (int i = 0; i < n; ++i)
        for(int j=0; j<n;++i)
        d[i][j] = rand();
    MyMatrix d1(n,1);
    d.copyM(d.vec, d1.vec, n);

    for (int i = 0; i < n; ++i)
          for(int j=0; j<n;++i){
        assert(d[i][j] == d1[i][j]);
    }

#ifdef _DEBUG
    std::cerr << "test matrix copy: OK" << std::endl;
#endif
    return true;
}

//Тест для нахождения под-матрицы
bool pod_matr(){
    size_t n = 3;
    //С матрицами все хорошо
    MyMatrix d(n,1);
    for(int j=0; j<n;++i)
        d[0][j]=1;
    for(int j=0; j<n;++i)
        d[1][j]=2;
    for(int j=0; j<n;++i)
        d[2][j]=3;
    //Выделяем матрицу 3х2
    //Выделили типа
    MyMatrix d1(3,2,1);
    for(int j=0; j<2;++i)
        d1[j][0]=1;
    for(int j=0; j<2;++i)
        d1[j][1]=2;
    for(int j=0; j<2;++i)
        d1[j][2]=3;
    assert(d==d1);

    //Размеры под-матрицы больше размеров самой матрицы
#ifdef _DEBUG
    std::cerr << "test matrix pod_matrix: OK" << std::endl;
#endif
    return true;
}

//Тест для транспонирования матрицы
bool tranponir();*/
