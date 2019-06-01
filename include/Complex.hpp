#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

namespace cplx {

    //declare

    class Complex {
      private:
        double re, im;

      public:

        //constructor

        Complex(); //default constructor
        Complex(double r, double i); //persion constructor
        Complex(Complex & num); //copy constructor

        //method

        double get_real() const; //get_real
        double get_imag() const; //get_imag

        void set_real(const double d); //set_real
        void set_imag(const double d); //set_imag

        //binary operator override

        Complex & operator =(const Complex & num); //assign

        Complex & operator +=(const Complex & num); //add assign
        Complex & operator -=(const Complex & num); //minus assign
        Complex & operator *=(const Complex & num); //multiple assign
        Complex & operator /=(const Complex & num); //divide assign

        Complex operator +(const Complex & num); //add
        Complex operator -(const Complex & num); //minus
        Complex operator *(const Complex & num); //multiple
        Complex operator /(const Complex & num); //divide

        bool operator ==(const Complex & num) const;
        bool operator !=(const Complex & num) const;

        //unary operator override

        Complex & operator +(); //positive
        Complex & operator -(); //negative

        Complex & operator ++(); //prefix increment
        Complex operator ++(const int dummy); //postfix increment

        //friend operator override

        friend std::ostream & operator <<(std::ostream & os, const Complex & num); //output
    };

    //define

    Complex::Complex(): re{0}, im{0} {} //default constructor

    Complex::Complex(double r, double i): re{r}, im{i} {} //persion constructor

    Complex::Complex(Complex & num): re{num.re}, im{num.im} {} //copy constructor

    double Complex::get_real() const {
        return re;
    }

    double Complex::get_imag() const {
        return im;
    }

    void Complex::set_real(const double d) {
        re = d;
    }

    void Complex::set_imag(const double d) {
        im = d;
    }

    Complex & Complex::operator=(const Complex & num) {
        if (this == &num) {
            throw "Cannot self assign!";
        } else {
            this->re = num.re;
            this->im = num.im;
        }

        return * this;
    }

    Complex & Complex::operator+=(const Complex & num) {
        this->re += num.re;
        this->im += num.im;

        return * this;
    }

    Complex & Complex::operator-=(const Complex & num) {
        this->re -= num.re;
        this->im -= num.im;

        return * this;
    }

    Complex & Complex::operator*=(const Complex & num) {
        this->re = this->re * num.re - this->im * num.im;
        this->im = this->re * num.im + this->im * num.re;

        return * this;
    }

    Complex & Complex::operator/=(const Complex & num) {
        this->re = (this->re * num.re + this->im * num.im) / (this->re * this->re + this->im * this->im);
        this->im = (this->im * num.re + this->re * num.im) / (this->re * this->re + this->im * this->im);

        return * this;
    }

    Complex Complex::operator+(const Complex & num) {
        Complex temp{* this};

        temp += num;

        return temp;
    }

    Complex Complex::operator-(const Complex & num) {
        Complex temp{* this};

        temp -= num;

        return temp;
    }

    Complex Complex::operator*(const Complex & num) {
        Complex temp{* this};

        temp *= num;

        return temp;
    }

    Complex Complex::operator/(const Complex & num) {
        Complex temp{* this};

        temp /= num;

        return temp;
    }

    Complex & Complex::operator+() {
        return * this;
    }

    Complex & Complex::operator-() {
        this->re *= -1;
        this->im *= -1;

        return * this;
    }

    Complex & Complex::operator++() {
        this->re++;

        return * this;
    }

    Complex Complex::operator++(const int dummy) {
        Complex temp{* this};

        ++(*this);

        return temp;
    }

    bool Complex::operator==(const Complex & num) const {
        return this->re == num.re && this->im == num.im;
    }

    bool Complex::operator!=(const Complex & num) const {
        return !(*this == num);
    }

    std::ostream & operator<<(std::ostream & os, const Complex & num) {
        os << num.re << "i + " << num.im << "j";

        return os;
    }
}

#endif
