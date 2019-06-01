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

    Complex & Complex::operator=(const Complex & object) {
        if (this != &object) {
            this->re = object.re;
            this->im = object.im;
        }

        return * this;
    }

    Complex & Complex::operator+=(const Complex & object) {
        if (this != &object) {
            this->re += object.re;
            this->im += object.im;
        } else {
            this->re *= 2;
            this->im *= 2;
        }

        return * this;
    }

    Complex & Complex::operator-=(const Complex & object) {
        if (this != &object) {
            this->re -= object.re;
            this->im -= object.im;
        } else {
            this->re = 0;
            this->im = 0;
        }

        return * this;
    }

    Complex & Complex::operator*=(const Complex & object) {
        if (this != &object) {
            this->re = this->re * object.re - this->im * object.im;
            this->im = this->re * object.im + this->im * object.re;
        } else {
            this->re = this->re * this->re - this->im * this->im;
            this->im = this->re * this->im + this->im * this->re;
        }

        return * this;
    }

    Complex & Complex::operator/=(const Complex & object) {
        if (this != &object) {
            this->re = (this->re * object.re + this->im * object.im) / (this->re * this->re + this->im * this->im);
            this->im = (this->im * object.re + this->re * object.im) / (this->re * this->re + this->im * this->im);
        } else {
            this->re = 1;
            this->im = 0;
        }

        return * this;
    }

    Complex Complex::operator+(const Complex & object) {
        Complex temp = *this;

        temp += object;

        return temp;
    }

    Complex Complex::operator-(const Complex & object) {
        Complex temp = *this;

        temp -= object;

        return temp;
    }

    Complex Complex::operator*(const Complex & object) {
        Complex temp = *this;

        temp *= object;

        return temp;
    }

    Complex Complex::operator/(const Complex & object) {
        Complex temp = *this;

        temp /= object;

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

    bool Complex::operator==(const Complex & object) const {
        return this->re == object.re && this->im == object.im;
    }

    bool Complex::operator!=(const Complex & object) const {
        return !(*this == object);
    }

    ostream & operator<<(ostream & os, const Complex & object) {
        os << object.re << "i + " << object.im << "j";

        return os;
    }
}
