#include "Complex.hpp"

using std::ostream;

namespace cplx {
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
        if (this != &cplxnum) {
            this->re = cplxnum.re;
            this->im = cplxnum.im;
        }

        return * this;
    }

    Complex & Complex::operator+=(const Complex & cplxnum) {
        if (this != &cplxnum) {
            this->re += cplxnum.re;
            this->im += cplxnum.im;
        } else {
            this->re *= 2;
            this->im *= 2;
        }

        return * this;
    }

    Complex & Complex::operator-=(const Complex & cplxnum) {
        if (this != &cplxnum) {
            this->re -= cplxnum.re;
            this->im -= cplxnum.im;
        } else {
            this->re = 0;
            this->im = 0;
        }

        return * this;
    }

    Complex & Complex::operator*=(const Complex & cplxnum) {
        if (this != &cplxnum) {
            this->re = this->re * cplxnum.re - this->im * cplxnum.im;
            this->im = this->re * cplxnum.im + this->im * cplxnum.re;
        } else {
            this->re = this->re * this->re - this->im * this->im;
            this->im = this->re * this->im + this->im * this->re;
        }

        return * this;
    }

    Complex & Complex::operator/=(const Complex & cplxnum) {
        if (this != &cplxnum) {
            this->re = (this->re * cplxnum.re + this->im * cplxnum.im) / (this->re * this->re + this->im * this->im);
            this->im = (this->im * cplxnum.re + this->re * cplxnum.im) / (this->re * this->re + this->im * this->im);
        } else {
            this->re = 1;
            this->im = 0;
        }

        return * this;
    }

    Complex Complex::operator+(const Complex & cplxnum) {
        Complex temp = *this;

        temp += cplxnum;

        return temp;
    }

    Complex Complex::operator-(const Complex & cplxnum) {
        Complex temp = *this;

        temp -= cplxnum;

        return temp;
    }

    Complex Complex::operator*(const Complex & cplxnum) {
        Complex temp = *this;

        temp *= cplxnum;

        return temp;
    }

    Complex Complex::operator/(const Complex & cplxnum) {
        Complex temp = *this;

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
        Complex temp = *this;

        ++(*this);

        return temp;
    }

    bool Complex::operator==(const Complex & cplxnum) const {
        return this->re == cplxnum.re && this->im == cplxnum.im;
    }

    bool Complex::operator!=(const Complex & cplxnum) const {
        return !(*this == cplxnum);
    }

    ostream & operator<<(ostream & os, const Complex & cplxnum) {
        os << cplxnum.re << "i + " << cplxnum.im << "j";

        return os;
    }
}
