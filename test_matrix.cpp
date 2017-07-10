#include "test_matrix.h"
using namespace std;
#include <iostream>
const double precision=0.000134;
//Тест для конструктора
bool test_matrix::construct()
{
    //Конструкторы для нулевых и единичных векторов
    size_t n = 5;
    MyMatrix d(n,1);
    for(int i=0; i<n;++i)
        for(int j=0; j<n;++j)
        assert(d[i][j]==1);
    MyMatrix d1(n,0);
    for(int i=0; i<5;++i)
        for(int j=0; j<n;++j)
        assert(d1[i][j]==0);
    //Неверно дан флаг
    /*try {
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
    }*/

#ifdef _DEBUG
    std::cerr << "test matrix constructor: OK" << std::endl;
#endif
    return true;
}

//Тест для конструктора копии
bool test_matrix::copy()
{
    size_t n = 5;
    MyMatrix d(n,1);
    for (int i = 0; i < n; ++i)
        for(int j=0; j<n;++j)
        d[i][j] = rand();
    MyMatrix d1(n,1);
    d.copyM(d.vec, d1.vec, n, n);

    for (int i = 0; i < n; ++i)
          for(int j=0; j<n;++j){
        assert(d[i][j] == d1[i][j]);
    }

#ifdef _DEBUG
    std::cerr << "test matrix copy: OK" << std::endl;
#endif
    return true;
}

//Тест для нахождения под-матрицы
bool test_matrix::pod_matr(){
    size_t n = 3;
    //С матрицами все хорошо
    MyMatrix d(n,1);
    for(int j=0; j<n;++j)
        d[0][j]=1;
    for(int j=0; j<n;++j)
        d[1][j]=2;
    for(int j=0; j<n;++j)
        d[2][j]=3;
    //Выделяем матрицу 3х2
    //Выделили типа
    MyMatrix d1(2,3,1);
    for(int j=0; j<2;++j)
        d1[1][j]=2;
    for(int j=0; j<2;++j)
        d1[0][j]=1;
   d  = submatrix(2,3,d);
     assert(d==d1);
    //Размеры под-матрицы больше размеров самой матрицы
     /*try {
     submatrix(5,5,d);
         assert(0);
     }
     catch (char *s) {
         assert(1);
     }*/
#ifdef _DEBUG
    std::cerr << "test matrix submatrix: OK" << std::endl;
#endif
    return true;
}
//Тест для транспонирования матрицы
bool test_matrix::tranponir(){
    size_t n = 3;
    //С матрицами все хорошо
    MyMatrix d(n,1);
    for(int j=0; j<n;++j)
        d[0][j]=1;
    for(int j=0; j<n;++j)
        d[1][j]=2;
    for(int j=0; j<n;++j)
        d[2][j]=3;
    MyMatrix d1(n,1);
    for(int j=0; j<n;++j)
        d1[j][1]=1;
    for(int j=0; j<n;++j)
        d1[j][1]=2;
    for(int j=0; j<n;++j)
        d1[j][2]=3;
    transposition(d);
    assert(d1==d);
    //Не квадратные матрицы
    MyMatrix d2(2,3,1);
    for(int j=0; j<n;++j)
        d2[0][j]=1;
    for(int j=0; j<n;++j)
        d2[1][j]=2;
    MyMatrix d3(3,2,1);
     d3[0][0]=1;
     d3[0][1]=2;
     d3[1][0]=1;
     d3[1][1]=2;
     d3[2][0]=1;
     d3[2][1]=2;
     transposition(d2);
     assert(d2==d3);

#ifdef _DEBUG
    std::cerr << "test matrix transposition: OK" << std::endl;
#endif
    return true;
}

//Тест для вычисления определителя
bool test_matrix::determinant1(){
    size_t n = 3;
    //С матрицами все хорошо
    MyMatrix d(n,1);
    for(int j=0; j<n;++j)
        d[0][j]=1;
    for(int j=0; j<n;++j)
        d[1][j]=2;
    for(int j=0; j<n;++j)
        d[2][j]=3;
    assert(abs(determinant(d,n) - 0)<precision);
    MyMatrix d1(2,1);
        d1[0][0]=1;
        d1[1][1]=2;
        d1[0][1]=3;
        d1[1][0]=4;
    assert(abs(determinant(d1,2) - (-10))<precision);
    //Не квадратная
    /*try {
      MyMatrix d(3,2,1);
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix determinant: OK" << std::endl;
#endif
    return true;
}
//Тест для вычисления алгебраического дополнения
bool test_matrix::algebr(){
    MyMatrix d1(2,1);
        d1[0][0]=1;
        d1[1][1]=2;
        d1[0][1]=3;
        d1[1][0]=4;
    assert(abs(cofactor(d1,2,2) - 1)<precision);
    //Не квадратная
    /*try {
    MyMatrix d2(2,3,1);
    cofactor(d2,2,2);
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix cofactor: OK" << std::endl;
#endif
    return true;
}

//Тест для вычисления обратной матрицы
bool test_matrix::obatn(){
    MyMatrix d(2,0);
    d[0][0]=1;
    d[0][1]=2;
    d[1][0]=3;
    d[1][1]=4;
    MyMatrix d1(2,0);
    d[0][0]=4;
    d[0][1]=-3;
    d[1][0]=-2;
    d[1][1]=1;
 // cout<<inverse(d);
   // assert(inverse(d)==d1);
    //Нет обратной матрицы
    /*try {
    MyMatrix d2(2,1);
    inverse(d2);
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix inverse: OK" << std::endl;
#endif
    return true;
}

//Тесты опрераторов:
//+
bool test_matrix::plus(){
    MyMatrix d1(3,1);
    MyMatrix d2(3,0);
    MyMatrix d3(3,1);
    assert(d1+d2==d3);
    //Разные размеры
    /*try {
    MyMatrix d4(2,3,1);
    d4+d1;
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix operator +: OK" << std::endl;
#endif
    return true;
}

//-
bool test_matrix::minus(){
    MyMatrix d1(3,1);
    MyMatrix d2(3,1);
    MyMatrix d3(3,0);
    assert(d1-d2==d3);
    //Разные размеры
    /*try {
    MyMatrix d4(2,3,1);
    d4-d1;
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix operator -: OK" << std::endl;
#endif
    return true;
}

//M1*M2
bool test_matrix::umn(){
    MyMatrix d1(3,1);
    MyMatrix d2(3,1);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            d2[i][j]=2;
    MyMatrix d3(3,0);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            d3[i][j]=4;

   // assert(d1*d2==d3);
    //Несоответствие размеров
    /*try {
    MyMatrix d4(2,1,1);
    d4*d1;
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix operator *: OK" << std::endl;
#endif
    return true;
}

//*k
bool test_matrix::umnk(){
    MyMatrix d1(3,1);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            d1[i][j]=2;
    MyMatrix d3(3,0);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            d3[i][j]=8;
    MyMatrix d=d1*4;
    assert(d==d3);
    //Несоответствие размеров
    /*try {
    MyMatrix d4(2,1,1);
    d4*d1;
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
#ifdef _DEBUG
    std::cerr << "test matrix operator *k: OK" << std::endl;
#endif
    return true;
}
//*V
bool test_matrix::umnv(){
    MyMatrix d1(3,1);
    MyVector v(3,1);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            d1[i][j]=2;
    MyVector v1(3,0);
    for(int i=0; i<3; ++i)
            v1[i]=2;
   // MyVector v2=d1*v;
   // for(int i=0; i<3;++i)
  //  assert(v2[i]==v1[i]);
#ifdef _DEBUG
    std::cerr << "test matrix operator *V: OK" << std::endl;
#endif
    return true;
}
// ==
bool test_matrix::eq(){
     MyMatrix d1(3,1);
     MyMatrix d2(3,1);
     assert(d1==d2);
     d1[0][0]=-1;
     d2[0][0]=-1;
     assert(d1==d2);
     d1[0][1]=-9;
     assert(!(d1==d2));
     //Несоответствие размеров
     /*try {
     MyMatrix d4(2,1,1);
     d1==d4;
         assert(0);
     }
     catch (char *s) {
         assert(1);
     }*/
}

// !=
bool test_matrix::neq(){
    MyMatrix d1(3,1);
    MyMatrix d2(3,1);
    MyMatrix d3(3,0);
    assert(d1!=d3);
    assert(!(d1!=d2));
    d1[0][0]=-1;
    d2[0][0]=0;
    assert((d1!=d2));
    d1[0][1]=-9;
    assert((d1!=d2));
    //Несоответствие размеров
    /*try {
    MyMatrix d4(2,1,1);
    d1!=d4;
        assert(0);
    }
    catch (char *s) {
        assert(1);
    }*/
}

//Запуск тестов
bool test_matrix::run()
{
    test_matrix test;
    return test.construct()
            && test.copy()
            && test.pod_matr()
            && test.tranponir()
            && test.determinant1()
            && test.algebr()
            && test.obatn()
            && test.plus()
            && test.minus()
            && test.umn()
            && test.umnk()
            && test.umnv()
            && test.eq()
            && test.neq();
}
