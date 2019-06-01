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
        Complex(Complex & cplxnum); //copy constructor

        //method

        double real() const;
        double imag() const;

        void real(const double d);
        void imag(const double d);

        //binary operator override

        Complex & operator =(const Complex & cplxnum);

        Complex & operator +=(const Complex & cplxnum);
        Complex & operator -=(const Complex & cplxnum);
        Complex & operator *=(const Complex & cplxnum);
        Complex & operator /=(const Complex & cplxnum);

        Complex operator +(const Complex & cplxnum);
        Complex operator -(const Complex & cplxnum);
        Complex operator *(const Complex & cplxnum);
        Complex operator /(const Complex & cplxnum);

        bool operator ==(const Complex & cplxnum) const;
        bool operator !=(const Complex & cplxnum) const;

        //unary operator override

        Complex & operator +();
        Complex & operator -();

        Complex & operator ++();
        Complex operator ++(const int dummy);

        //friend operator override

        friend std::ostream & operator <<(std::ostream & os, const Complex & cplxnum);
    };

    //define

    Complex::Complex(): re{0}, im{0} {} //default constructor

    Complex::Complex(double r, double i): re{r}, im{i} {} //persion constructor

    Complex::Complex(Complex & cplxnum): re{cplxnum.re}, im{cplxnum.im} {} //copy constructor

    double Complex::real() const {
        return re;
    }

    double Complex::imag() const {
        return im;
    }

    void Complex::real(const double d) {
        re = d;
    }

    void Complex::imag(const double d) {
        im = d;
    }

    Complex & Complex::operator=(const Complex & cplxnum) {
        if (this == &cplxnum) {
            throw "Cannot self assign!";
        } else {
            this->re = cplxnum.re;
            this->im = cplxnum.im;
        }

        return * this;
    }

    Complex & Complex::operator+=(const Complex & cplxnum) {
        this->re += cplxnum.re;
        this->im += cplxnum.im;

        return * this;
    }

    Complex & Complex::operator-=(const Complex & cplxnum) {
        this->re -= cplxnum.re;
        this->im -= cplxnum.im;

        return * this;
    }

    Complex & Complex::operator*=(const Complex & cplxnum) {
        this->re = this->re * cplxnum.re - this->im * cplxnum.im;
        this->im = this->re * cplxnum.im + this->im * cplxnum.re;

        return * this;
    }

    Complex & Complex::operator/=(const Complex & cplxnum) {
        this->re = (this->re * cplxnum.re + this->im * cplxnum.im) / (this->re * this->re + this->im * this->im);
        this->im = (this->im * cplxnum.re + this->re * cplxnum.im) / (this->re * this->re + this->im * this->im);

        return * this;
    }

    Complex Complex::operator+(const Complex & cplxnum) {
        Complex temp{* this};

        temp += cplxnum;

        return temp;
    }

    Complex Complex::operator-(const Complex & cplxnum) {
        Complex temp{* this};

        temp -= cplxnum;

        return temp;
    }

    Complex Complex::operator*(const Complex & cplxnum) {
        Complex temp{* this};

        temp *= cplxnum;

        return temp;
    }

    Complex Complex::operator/(const Complex & cplxnum) {
        Complex temp{* this};

        temp /= cplxnum;

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

    bool Complex::operator==(const Complex & cplxnum) const {
        return this->re == cplxnum.re && this->im == cplxnum.im;
    }

    bool Complex::operator!=(const Complex & cplxnum) const {
        return !(*this == cplxnum);
    }

    std::ostream & operator<<(std::ostream & os, const Complex & cplxnum) {
        os << cplxnum.re << "i + " << cplxnum.im << "j";

        return os;
    }
}

#endif
