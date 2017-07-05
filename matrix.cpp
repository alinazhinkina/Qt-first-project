#include "matrix.h"

using namespace std;

MyMatrix::MyMatrix():m(0), n(0), vec(nullptr) {}

MyMatrix::MyMatrix(size_t count, int flag) {

   if (count < 0)
                throw std::runtime_error("error");

   this->m=count;
   this->n=count;
   vec = new MyVector[count];
           for (int i = 0; i < count; ++i)
               vec[i] = MyVector(count,flag);
    }

MyMatrix::MyMatrix(size_t i, size_t j, int flag){
    if ((i < 0) || (j < 0))
                 throw std::runtime_error("error");

    this->m=i;
    this->n=j;
    vec = new MyVector[i];
            for (int k = 0; k < i; ++k)
                vec[k]=MyVector(j,flag);
}

MyMatrix::~MyMatrix()
{
    qDebug() << "Udalenie matrix";
    if (vec)
    delete[] vec;
    qDebug() << "Matrix udalen";
}

void MyMatrix::copyM(const MyVector * from, MyVector * const to, const size_t ii, const size_t jj)
{
     qDebug() << "000000000";
    for (int i = 0; i < ii; ++i)
    for (int j = 0; j < jj; ++j)
         qDebug() << to[i][j];

    for (int i = 0; i < ii; ++i)
        for (int j = 0; j < ii; ++j)
             to[i][j] = from[i][j];
}

MyMatrix::MyMatrix(const MyMatrix & m):m(m.m),n(m.n)
{
    qDebug() << m.n;
    this->vec = new MyVector[m.m];
    copyM(m.vec, vec, m.m ,m.n);
}

MyVector MyMatrix::operator[](int ind1) const
{
        if ((ind1 >= m) && (ind1 < 0))
                throw std::runtime_error("errrrror");
        //
    return vec[ind1];
}

MyVector & MyMatrix::operator[](int ind1)
{
        if ((ind1 >= m) && (ind1 < 0))
                throw std::runtime_error("errrrror");
        //
    return vec[ind1];
}

MyMatrix submatrix(int ind1, int ind2, MyMatrix mm){

       if ((ind1 > mm.m) && (ind2 > mm.n))
           throw std::runtime_error("errrrror");
       if ((ind1 < 0) && (ind2 < 0))
           throw std::runtime_error("errrrror");
//       if (*this == nullptr)
           //throw std::runtime_error("errrrror");
       MyMatrix v(ind1,ind2,0);
       for (int i = 0; i < ind1; ++i)
           for (int j = 0; j < ind2; ++j)
               v[i][j] = mm[i][j];

     return v;
}

void transposition(MyMatrix &a)
{
    //       if (*this == nullptr)
               //throw std::runtime_error("errrrror");
    MyVector *b = new MyVector[a.n];
    for (int i = 0; i < a.n; i++)
        b[i] = MyVector(a.m,0);
    for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.m; j++)
        b[i][j] = a[j][i];
    size_t d = a.m;
    a.m = a.n;
    a.n = d;
    a.vec = b;
}

MyMatrix &MyMatrix::operator=(const MyMatrix &mat){
    if ((m < mat.m) && (n < mat.n)){
        delete[] vec;
        vec = new MyVector[mat.m];
    }
    m = mat.m;
    n = mat.n;
    copyM(mat.vec, vec, mat.m, mat.n);
    return *this;
}

