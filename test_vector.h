#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include "vector.h"
#include <cassert>
class test_vector {

    //
    // Тестируемые функции
    //
    //Тест для конструктора
    bool construct();
    //Тест для конструктора копии
    bool copy();
    //Тест для нахождения нормы вектора
    bool norma();
    //Тесты опрераторов:
    //+
    bool plus();
    //-
    bool minus();
    //V1*V2
    bool umn();
    //*k
    bool umnk();

public:
    static bool run();
};

#endif // TEST_VECTOR_H
