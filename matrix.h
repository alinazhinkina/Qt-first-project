#ifndef MATRIX_H
#define MATRIX_H

#include <QException>
#include <QDebug>
#include "vector.h"

using namespace std;

class matrix1
{
private:
    vector1 *vec;
    size_t count;
    // Вспомогательная функция копирования массива
    void copy(const vector1 * from, vector1 * to, size_t count);
public:
    matrix1();
    matrix1(size_t count, int flag);
    ~matrix1();
    matrix1(const matrix1& m);
    //datatype &operator[](int ind1, int ind2);
    //datatype operator[](int ind1, int ind2) const;


};

#endif // MATRIX_H
