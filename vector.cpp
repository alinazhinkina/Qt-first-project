
#include "vector.h"
#include <QDebug>
using namespace std;
MyVector::MyVector() :data(nullptr), size(0) {}

MyVector::MyVector(size_t size) {

   if (size < 0)
                throw std::runtime_error("error");
   //
   this->size = size;

    data = new int[size];
}

double MyVector::norma(){
    double sum = 0;
     for (int i=0; i<size; ++i)
         sum += abs(data[i])*abs(data[i]);
     return sqrt(sum);
}

int MyVector::operator[](int index) const
{
        if (index >= size)
                throw std::runtime_error("errrrror");
        //
    return data[index];
}

int & MyVector::operator[](int index)
{
        //if (index >= size)
          //      throw std::runtime_error("errrrror");
        //
    return data[index];
}



MyVector::~MyVector()
{

    if (data)
    delete[] data;

}

MyVector &MyVector::operator+(const MyVector v)
{
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                data[i] += v.data[i];
        return *this;
}

MyVector &MyVector::operator-(const MyVector v)
{
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                data[i] -= v.data[i];
        return *this;
}

MyVector &MyVector::operator*(double k) {
        for (int i = 0; i < size; ++i)
                data[i] = data[i] * k;
        return *this;
}

double MyVector::operator*(const MyVector &v) {
        double sum = 0;
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                sum += data[i] * v.data[i];
       // qDebug() << sum;
        return sum;
}

MyVector::MyVector(size_t size, int flag) {

   if (size < 0)
                throw std::runtime_error("error");
   //
   this->size = size;

    data = new int[size];
    if(flag!=1 && flag!=0)
         throw "error";

    for(int i=0; i<size; ++i)
        data[i]=flag;

}

void MyVector::copy(const int * from, int * to, size_t size)
{
    for (int i = 0; i < size; ++i) {
        to[i] = from[i];
    }
}

MyVector::MyVector(const MyVector& v):size(v.size)
{
    this->data = new int[size];
    copy(v.data, data, size);
}

MyVector &MyVector::operator=(const MyVector &v){
    if (size < v.size){
        delete[] data;
        data = new int[v.size];
    }
    size = v.size;
    copy(v.data, data, size);
    return *this;
}

int* MyVector::get_data(){
    return this->data;
}

size_t MyVector::get_size(){
    return this->size;
}
