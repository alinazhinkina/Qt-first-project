#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include "matrix.h"
#include <cassert>
class test_matrix {

    //
    // Тестируемые функции
    //
    //Тест для конструктора
    bool construct();
    //Тест для конструктора копии
    bool copy();
    //Тест для нахождения под-матрицы
    bool pod_matr();
    //Тест для транспонирования матрицы
    bool tranponir();
    //Тест для вычисления определителя
    bool determinant1();
    //Тест для вычисления алгебраического дополнения
    bool algebr();
    //Тест для вычисления обратной матрицы
    bool obatn();
    //Тесты опрераторов:
    //+
    bool plus();
    //-
    bool minus();
    //M1*M2
    bool umn();
    //*k
    bool umnk();
    //*V
    bool umnv();
    // ==
    bool eq();
    // !=
    bool neq();

public:
    static bool run();
};

#endif // TEST_MATRIX_H
