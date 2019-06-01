#include "Complex.hpp"

using std::ostream;

namespace cplx {
    double complex::real() const {
        return re;
    }

    double complex::imag() const {
        return im;
    }

    void complex::real(const double d) {
        re = d;
    }

    void complex::imag(const double d) {
        im = d;
    }

    complex & complex::operator=(const complex & object) {
        if (this != &object) {
            this->re = object.re;
            this->im = object.im;
        }

        return * this;
    }

    complex & complex::operator+=(const complex & object) {
        if (this != &object) {
            this->re += object.re;
            this->im += object.im;
        } else {
            this->re *= 2;
            this->im *= 2;
        }

        return * this;
    }

    complex & complex::operator-=(const complex & object) {
        if (this != &object) {
            this->re -= object.re;
            this->im -= object.im;
        } else {
            this->re = 0;
            this->im = 0;
        }

        return * this;
    }

    complex & complex::operator*=(const complex & object) {
        if (this != &object) {
            this->re = this->re * object.re - this->im * object.im;
            this->im = this->re * object.im + this->im * object.re;
        } else {
            this->re = this->re * this->re - this->im * this->im;
            this->im = this->re * this->im + this->im * this->re;
        }

        return * this;
    }

    complex & complex::operator/=(const complex & object) {
        if (this != &object) {
            this->re = (this->re * object.re + this->im * object.im) / (this->re * this->re + this->im * this->im);
            this->im = (this->im * object.re + this->re * object.im) / (this->re * this->re + this->im * this->im);
        } else {
            this->re = 1;
            this->im = 0;
        }

        return * this;
    }

    complex complex::operator+(const complex & object) {
        complex temp = *this;

        temp += object;

        return temp;
    }

    complex complex::operator-(const complex & object) {
        complex temp = *this;

        temp -= object;

        return temp;
    }

    complex complex::operator*(const complex & object) {
        complex temp = *this;

        temp *= object;

        return temp;
    }

    complex complex::operator/(const complex & object) {
        complex temp = *this;

        temp /= object;

        return temp;
    }

    complex & complex::operator+() {
        return * this;
    }

    complex & complex::operator-() {
        this->re *= -1;
        this->im *= -1;

        return * this;
    }

    complex & complex::operator++() {
        this->re++;

        return * this;
    }

    complex complex::operator++(const int dummy) {
        complex temp = *this;

        ++(*this);

        return temp;
    }

    bool complex::operator==(const complex & object) const {
        return this->re == object.re && this->im == object.im;
    }

    bool complex::operator!=(const complex & object) const {
        return !(*this == object);
    }

    ostream & operator<<(ostream & os, const complex & object) {
        os << object.re << "i + " << object.im << "j";

        return os;
    }
}
