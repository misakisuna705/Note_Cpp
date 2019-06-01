#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdexcept>

namespace Misaki {

    //declare

    template <class ctype> class Array {
      private:
        int size;
        ctype * data;

      public:

        //constructor

        Array(); //default constructor
        explicit Array(const int & n); //constructor
        Array(const Array<ctype> & Arr); //copy constructor

        //destructor

        ~Array();

        //method

        int get_size() const; //get_size
        void set_size(const int & n); //set_size
        ctype get_at(const int & index) const; //get_at
        void set_at(const int & index, const ctype & value); //set_at

        //binary operator

        Array<ctype> & operator =(const Array<ctype> & Arr); //assignment override
        Array<ctype> & operator +(const Array<ctype> & Arr); //addition override

        //unary operator
    };

    //define

    template <class ctype> Array<ctype>::Array(): data{nullptr}, size{0} {} //default constructor

    template <class ctype> Array<ctype>::Array(const int & n): data{nullptr} { //constructor
        set_size(n);
    }

    template <class ctype> Array<ctype>::Array(const Array<ctype> & Arr) { //copy constructor
        set_size(Arr.size);
        for (int i = 0; i < size; ++i) {
            data[i] = Arr.data[i];
        }
    }

    template <class ctype> Array<ctype>::~Array() { //destructor
        delete [] data;
        data = nullptr;
    }

    template <class ctype> int Array<ctype>::get_size() const { //get_size
        return size;
    }

    template <class ctype> void Array<ctype>::set_size(const int & n) { //set_size
        if (data != nullptr) {
            throw "Array has been initialized!";
        } else {
            size = n;
            data = new int[n];
        }
    }

    template <class ctype> ctype Array<ctype>::get_at(const int & index) const { //get_at
        if (0 <= index && index < size ) {
            return data[index];
        } else {
            throw std::out_of_range("Index is out of range!");
        }
    }

    template <class ctype> void Array<ctype>::set_at(const int & index, const ctype & value) { //set_at
        if (0 <= index && index < size ) {
            data[index] = value;
        } else {
            throw std::out_of_range("Index is out of range!");
        }
    }

    template <class ctype> Array<ctype> & Array<ctype>::operator=(const Array<ctype> & Arr) { //assignment override
        if (data == nullptr) {
            set_size(Arr.size);
            for (int i = 0; i < size; ++i) {
                data[i] = Arr.data[i];
            }
        } else if (size != Arr.size) {
            throw "Size is not the same!";
        } else if (this == &Arr) {
            throw "Cannot self assign";
        } else {
            for (int i = 0; i < size; ++i) {
                data[i] = Arr.data[i];
            }
        }

        return * this;
    }

    template <class ctype> Array<ctype> & Array<ctype>::operator+(const Array<ctype> & Arr) { //addition override
        if (size != Arr.size) {
            throw "Size is not the same!";
        } else {
            Array<ctype> tmp = *this;

            for (int i = 0; i < size; ++i) {
                tmp.data[i] += Arr.data[i];
            }
        }

        return * this;
    }
}

#endif
