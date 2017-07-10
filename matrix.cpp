#include "matrix.h"
#include <iostream>

using namespace std;
const double precision=0.000134;

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

    if (vec)
    delete[] vec;

}

void MyMatrix::copyM(const MyVector * from, MyVector * const to, const size_t ii, const size_t jj)
{
    for (int i = 0; i < ii; ++i)
        for (int j = 0; j < ii; ++j)
             to[i][j] = from[i][j];
}

MyMatrix::MyMatrix(const MyMatrix & mat):m(mat.m),n(mat.n)
{

    this->vec = new MyVector[mat.m];
    for (int k = 0; k < mat.m; ++k)
        vec[k]=MyVector(mat.n,0);
    copyM(mat.vec, vec, mat.m ,mat.n);
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

MyMatrix &MyMatrix::operator+(const MyMatrix mat)
{
        if ((mat.m != m) && (mat.n != n)) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < m; i++)
                vec[i] = vec[i] + mat.vec[i];
        return *this;
}

MyMatrix &MyMatrix::operator-(const MyMatrix mat)
{
        if ((mat.m != m) && (mat.n != n)) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < m; i++)
                vec[i] = vec[i] - mat.vec[i];
        return *this;
}

MyMatrix &MyMatrix::operator*(double k) {
        for (int i = 0; i < m; ++i)
                vec[i] = vec[i] * k;
        return *this;
}

MyVector &MyMatrix::operator*(MyVector &v){
    if (v.get_size() != m) {
            throw std::runtime_error("Error");
    }
    MyVector out(m, 0);
    for (int i = 0; i < m; ++i)
            out[i] = vec[i] * v;
    return out;
}

MyMatrix &MyMatrix::operator*(MyMatrix &mat){
    if (mat.m != n) {
            throw std::runtime_error("Error");
    }
    MyMatrix out(m, mat.n, 0);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            out[i][j] = vec[i] * mat.vec[j];
   // qDebug() << "operator * out";
   // cout << out;
    return out;
}

MyMatrix submatrix(int ind1, int ind2, MyMatrix &mm){

       if ((ind1 > mm.m) && (ind2 > mm.n))
           throw std::runtime_error("errrrror");
       if ((ind1 < 0) && (ind2 < 0))
           throw std::runtime_error("errrrror");
       //if (*this == nullptr)
      //       throw std::runtime_error("errrrror");
       MyMatrix v(ind1,ind2,0);
       for (int i = 0; i < ind1; ++i)
           for (int j = 0; j < ind2; ++j)
               v[i][j] = mm[i][j];

     return v;
}

void transposition(MyMatrix &a)
{
  //  if (*this == nullptr)
  //     throw std::runtime_error("errrrror");
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

MyVector MyMatrix::get_vec(){
    return *(this->vec);
}

bool operator==( MyMatrix &m1, MyMatrix &m2){
    if (m1.get_vec().get_size() != m2.get_vec().get_size()) {
    throw domain_error("Error");
    }
    bool k = true;
    int i = 0;
    while (k && i < m1.get_vec().get_size()){
    if (abs(m1.get_vec().get_data()[i] - m2.get_vec().get_data()[i]) < precision) {
         ++i;
    }
    else
        k = false;
    }
    return k;
}

bool operator!=(MyMatrix &m1, MyMatrix &m2){
    return !(m1 == m2);
}

double determinant(MyMatrix &a, size_t z){
 /*   if ((a != nullptr) && (a.m == a.n)){

}*/

   MyMatrix b(z,z,0);
    if (z == 1) return a[0][0];


    double sum = 0;
    for (int i = 0; i < z; i++){

        for (int k = 0; k < z - 1; k++)
        for (int j = 0; j < i; j++)
            b[k][j] = a[k+1][j];
        for (int k = 0; k < z - 1; k++)
        for (int j = i; j < z -1; j++)
            b[k][j] = a[k+1][j + 1];
        if ((i % 2) == 0)
            sum += a[0][i] * determinant(b, z - 1);

        else
            sum += ((-1)*a[0][i] * determinant(b, z - 1));

    }

    return sum;

}

void delete_column(MyMatrix &a, size_t m, size_t n){
    MyMatrix h(a.m-1, a.n-1, 0);
    int ki = -1;
    int kj = -1;
    for (int i = 0; i < a.m; ++i){
        if  (i != m){
            ++ki;
            kj = -1;
            for (int j = 0; j < a.n; ++j){
            if (j != n){
                ++kj;
                h[ki][kj] = a[i][j];
            }
            }
        }
    }
    a.m = a.m-1;
    a.n = a.n-1;
    a = h;
}

std::ostream &operator<<(std::ostream &os, const MyMatrix &m){
    for (int i = 0; i < m.m; ++i){
        os << endl;
        for (int j = 0; j < m.n; ++j)
                        os << m[i][j] << "   ";
    }
    os << endl << endl;
    return os;
}

QTextStream &operator<<(QTextStream &os, const MyMatrix &m){
    for (int i = 0; i < m.m; ++i)
                   for (int j = 0; j < m.n; ++j)
                        os << m[i][j];
    return os;
}

std::istream &operator>>(std::istream &is, MyMatrix &m){
    for (int i = 0; i < m.m; ++i)
        for (int j = 0; j < m.n; ++j){
            qDebug() << "Input an element";
            is >> m[i][j];
        }
    return is;
}

QTextStream &operator>>(QTextStream &is, MyMatrix &m){
    for (int i = 0; i < m.m; ++i)
                   for (int j = 0; j < m.n; ++j)
                        is >> m[i][j];
    return is;
}

double cofactor(MyMatrix &a, size_t m, size_t n){
    m=m-1;
    n=n-1;
    MyMatrix b(a.m-1, a.n-1, 0);
    delete_column(a, m, n);
    b = a;
    double s;
   // cout << b;
    if ((m + n) %2 == 0)
        s = determinant(b, b.m);
    else
        s = (-1)*determinant(b, b.m);
    return s;
}

MyMatrix inverse(MyMatrix &a){
    double p = determinant(a, a.m);
    MyMatrix r(a.n, a.m, 0);
    if (p){
        MyMatrix d(a.m, a.n, 0);
        for (int i = -1; i < a.m-1; ++i)
            for (int j = -1; j < a.n-1; ++j){
                d[i][j]=cofactor(a, i+1, j+1);
                //qDebug() << d[i][j];
            }
        transposition(d);
        r = d * (1 / p);
    }
    return r;
}

bool check(MyMatrix &m1, MyMatrix &m2){
  //  if (m1.n != m2.m) {
      //      throw std::runtime_error("Error");
    //}
    MyMatrix E(m1.m, m2.n, 1);
    MyMatrix out(m1.m, m2.n, 1);
    out = m1 * m2;
    cout << out;
    return out == E;
}
