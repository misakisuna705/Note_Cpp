#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

namespace cplx {
    class complex {
      private:
        double re, im;

      public:
        complex(double r, double i): re{r}, im{i} {}
        explicit complex(double r): re{r}, im{0} {}
        complex(): re{0}, im{0} {}
        complex(complex & object): re{object.re}, im{object.im} {}

        double real() const;
        double imag() const;

        void real(const double d);
        void imag(const double d);

        complex & operator =(const complex & object);

        complex & operator +=(const complex & object);
        complex & operator -=(const complex & object);
        complex & operator *=(const complex & object);
        complex & operator /=(const complex & object);

        complex operator +(const complex & object);
        complex operator -(const complex & object);
        complex operator *(const complex & object);
        complex operator /(const complex & object);

        complex & operator +();
        complex & operator -();

        complex & operator ++();
        complex operator ++(const int dummy);

        bool operator ==(const complex & object) const;
        bool operator !=(const complex & object) const;

        friend std::ostream & operator <<(std::ostream & os, const complex & object);
    };
}

#endif
