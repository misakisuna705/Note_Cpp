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
        Complex(Complex & cplxnum): re{cplxnum.re}, im{cplxnum.im} {}

        double real() const;
        double imag() const;

        void real(const double d);
        void imag(const double d);

        Complex & operator =(const Complex & cplxnum);

        Complex & operator +=(const Complex & cplxnum);
        Complex & operator -=(const Complex & cplxnum);
        Complex & operator *=(const Complex & cplxnum);
        Complex & operator /=(const Complex & cplxnum);

        Complex operator +(const Complex & cplxnum);
        Complex operator -(const Complex & cplxnum);
        Complex operator *(const Complex & cplxnum);
        Complex operator /(const Complex & cplxnum);

        Complex & operator +();
        Complex & operator -();

        Complex & operator ++();
        Complex operator ++(const int dummy);

        bool operator ==(const Complex & cplxnum) const;
        bool operator !=(const Complex & cplxnum) const;

        friend std::ostream & operator <<(std::ostream & os, const Complex & cplxnum);
    };
}

#endif
