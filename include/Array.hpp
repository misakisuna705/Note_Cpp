#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
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
        explicit Array(const int & size); //persion constructor
        Array(const Array<ctype> & Arr); //copy constructor

        //destructor

        ~Array();

        //method

        int get_size() const; //get_size
        void set_size(const int & n); //set_size
        ctype get_at(const int & index) const; //get_at
        void set_at(const int & index, const ctype & value); //set_at

        //binary operator override

        Array<ctype> & operator =(const Array<ctype> & Arr); //assignment
        Array<ctype> operator +(const Array<ctype> & Arr) const; //addition

        //unary operator override

        Array<ctype> & operator -(); //negation
        Array<ctype> & operator ++(); //prefix increment
        Array<ctype> operator ++(const int dummy); //postfix increment
        ctype & operator [](const int & index) const; //index

        //friend operator override

        friend std::istream & operator >>(std::istream & is, const Array<ctype> & Arr); //input
        friend std::ostream & operator <<(std::ostream & os, const Array<ctype> & Arr); //output
    };

    //define

    template <class ctype> Array<ctype>::Array(): data{nullptr}, size{0} {} //default constructor

    template <class ctype> Array<ctype>::Array(const int & size): data{nullptr} { //constructor
        set_size(size);
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

    template <class ctype> Array<ctype> & Array<ctype>::operator=(const Array<ctype> & Arr) { //assignment
        if (data == nullptr) {
            set_size(Arr.size);
            for (int i = 0; i < size; ++i) {
                data[i] = Arr.data[i];
            }
        } else if (size != Arr.size) {
            throw "Size is not the same!";
        } else if (this == &Arr) {
            throw "Cannot self assign!";
        } else {
            for (int i = 0; i < size; ++i) {
                data[i] = Arr.data[i];
            }
        }

        return * this;
    }

    template <class ctype> Array<ctype> Array<ctype>::operator+(const Array<ctype> & Arr) const { //addition
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

    template <class ctype> Array<ctype> & Array<ctype>::operator-() { //negation
        for (int i = 0; i < size; ++i) {
            data[i] = -data[i];
        }

        return * this;
    }

    template <class ctype> Array<ctype> & Array<ctype>::operator ++() { //prefix increment
        for (int i = 0; i < size; ++i) {
            data[i]++;
        }

        return * this;
    }

    template <class ctype> Array<ctype> Array<ctype>::operator ++(const int dummy) { //postfix increment
        Array<ctype> tmp{* this};

        for (int i = 0; i < size; ++i) {
            data[i]++;
        }

        return tmp;
    }

    template <class ctype> ctype & Array<ctype>::operator[](const int & index) const { //index
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range!");
        } else {
            return data[index];
        }
    }

    template <class ctype> std::istream & operator >>(std::istream & is, const Array<ctype> & Arr) { //input
        for (int i = 0; i < Arr.size; i++) {
            is >> Arr.data[i];
        }

        return is;
    }



    template <class ctype> std::ostream & operator <<(std::ostream & os, const Array<ctype> & Arr) { //output
        for (int i = 0; i < Arr.size; i++) {
            os << " " << Arr.data[i];
        }

        return os;
    }
}

#endif
