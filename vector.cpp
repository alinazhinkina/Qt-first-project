
#include "vector.h"

using namespace std;
vector1::vector1() :data(nullptr), size(0) {}

vector1::vector1(size_t size) {

   if (size < 0)
                throw std::runtime_error("error");
   //
   this->size = size;

    data = new int[size];
}

double vector1::norma(){
    double sum = 0;
     for (int i=0; i<size; ++i)
         sum += abs(data[i])*abs(data[i]);
     return sqrt(sum);
}

int vector1::operator[](int index) const
{
        if (index >= size)
                throw std::runtime_error("errrrror");
        //
    return data[index];
}

int & vector1::operator[](int index)
{
        if (index >= size)
                throw std::runtime_error("errrrror");
        //
    return data[index];
}



vector1::~vector1()
{
    delete[] data;
}

vector1 &vector1::operator+(const vector1 v)
{
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                data[i] += v.data[i];
        return *this;
}

vector1 &vector1::operator-(const vector1 v)
{
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                data[i] -= v.data[i];
        return *this;
}

vector1 &vector1::operator*(double k) {
        for (int i = 0; i < size; ++i)
                data[i] = data[i] * k;
        return *this;
}

double vector1::operator*(const vector1 &v) {
        double sum = 0;
        if (size != v.size) {
                throw std::runtime_error("Error");
        }
        for (int i = 0; i < size; i++)
                sum += data[i] * v.data[i];
        qDebug() << sum;
        return sum;
}

vector1::vector1(size_t size, int flag) {

   if (size < 0)
                throw std::runtime_error("error");
   //
   this->size = size;

    data = new int[size];
    if(flag!=1 && flag!=0)
         throw "error";

    for(int i=0; i<size; ++i)
        data[i]=flag;
    qDebug() << "***";
}

void vector1::copy(const int * from, int * to, size_t size)
{
    for (int i = 0; i < size; ++i) {
        to[i] = from[i];
    }
}

vector1::vector1(const vector1& v)
{
    size = v.size;
    data = new int[size];
    copy(v.data, data, size);
}

