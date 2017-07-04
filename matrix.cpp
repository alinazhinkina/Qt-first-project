#include "matrix.h"

using namespace std;

matrix1::matrix1():count(0), vec(nullptr) {}

matrix1::matrix1(size_t count, datatype flag) {

   if (count < 0)
                throw std::runtime_error("error");


   vec = new vector1[count];
           for (int i = 0; i < count; ++i)
               for (int j = 0; j < count; ++j)
                   vec[i].data[j] = flag;
}

matrix1::~matrix1()
{
    delete[] vec;
}

void matrix1::copy(const vector1 * from, vector1 * const to, const size_t count)
{
    for (int i = 0; i < count; ++i)
        to[i] = from[i];
}

matrix1::matrix1(const matrix1 & m):count(m.count)
{
    this->vec = new vector1(count);
    copy(m.vec, vec, count);
}
