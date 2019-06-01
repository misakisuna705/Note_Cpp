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
        Array<ctype> operator +(const Array<ctype> & Arr) const; //addition override

        //unary operator

        Array<ctype> & operator -(); //negation override
        ctype & operator [](const int & index) const;
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
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range!");
        } else {
            return data[index];
        }
    }

    template <class ctype> void Array<ctype>::set_at(const int & index, const ctype & value) { //set_at
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range!");
        } else {
            data[index] = value;
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

    template <class ctype> Array<ctype> Array<ctype>::operator+(const Array<ctype> & Arr) const { //addition override
        if (size != Arr.size) {
            throw "Size is not the same!";
        } else {
            Array<ctype> tmp{* this};

            for (int i = 0; i < size; ++i) {
                tmp.data[i] += Arr.data[i];
            }

            return tmp;
        }
    }

    template <class ctype> Array<ctype> & Array<ctype>::operator-() { //negation override
        for (int i = 0; i < size; ++i) {
            data[i] = -data[i];
        }

        return * this;
    }

    template <class ctype> ctype & Array<ctype>::operator[](const int & index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range!");
        } else {
            return data[index];
        }
    }
}

#endif
