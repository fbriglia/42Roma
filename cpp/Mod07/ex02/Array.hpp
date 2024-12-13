#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include "iostream"

template <typename T> class Array {
    private:
        T*  Data;
        int _size;
    public:
        Array(): Data(NULL), _size(0) {}
        Array(unsigned int i): Data(new T[i]), _size(i) {}
        Array(const Array& A)
        {
            *this = A;
        }
        Array& operator=(const Array& A)
        {
            if (this == &A)
                return *this;
            _size = A._size;
            delete[] Data;
            Data = new T[_size];
            for (int i =0; i < A._size; i++)
                Data[i] = A.Data[i];
            return *this;
        }
        T& operator[](int i)
        {
            if (i >= size() || i < 0)
                throw std::out_of_range("index out of range");
            return Data[i];
        }
        int size()
        {
            return _size;
        }
        ~Array(){
            if (Data)
            {
                delete[] Data;
            }
        }

};

#endif