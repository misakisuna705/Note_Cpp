#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdexcept>

namespace Misaki {
    template <class ctype> class Array {
      private:
        int size;
        ctype * data;

      public:
        Array();
        explicit Array(const int & n);
        ~Array();

        int get_size() const;
        void set_size(const int & n);

        ctype get_at(const int & index) const;
        void set_at(const int & index, const ctype & value);
    };

    template <class ctype> Array<ctype>::Array() {
        data = nullptr;
        size = 0;
    }

    template <class ctype> Array<ctype>::Array(const int & n) {
        data = nullptr;
        set_size(n);
    }

    template <class ctype> Array<ctype>::~Array() {
        delete [] data;
        data = nullptr;
    }

    template <class ctype> int Array<ctype>::get_size() const {
        return size;
    }

    template <class ctype> void Array<ctype>::set_size(const int & n) {
        if (data != nullptr) {
            throw "Array has been initialized!";
        } else {
            size = n;
            data = new int[n];
        }
    }

    template <class ctype> ctype Array<ctype>::get_at(const int & index) const {
        if (0 <= index && index < size ) {
            return data[index];
        } else {
            throw std::out_of_range("Index is out of range!");
        }
    }

    template <class ctype> void Array<ctype>::set_at(const int & index, const ctype & value) {
        if (0 <= index && index < size ) {
            data[index] = value;
        } else {
            throw std::out_of_range("Index is out of range!");
        }
    }
}

#endif
