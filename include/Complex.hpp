#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

namespace cplx {
    class Complex {
      private:
        double re, im;

      public:
        Complex(): re{0}, im{0} {}
        Complex(double r, double i): re{r}, im{i} {}
        Complex(Complex & object): re{object.re}, im{object.im} {}

        double real() const;
        double imag() const;

        void real(const double d);
        void imag(const double d);

        Complex & operator =(const Complex & object);

        Complex & operator +=(const Complex & object);
        Complex & operator -=(const Complex & object);
        Complex & operator *=(const Complex & object);
        Complex & operator /=(const Complex & object);

        Complex operator +(const Complex & object);
        Complex operator -(const Complex & object);
        Complex operator *(const Complex & object);
        Complex operator /(const Complex & object);

        Complex & operator +();
        Complex & operator -();

        Complex & operator ++();
        Complex operator ++(const int dummy);

        bool operator ==(const Complex & object) const;
        bool operator !=(const Complex & object) const;

        friend std::ostream & operator <<(std::ostream & os, const Complex & object);
    };
}

#endif
