#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <ostream>
#include <initializer_list>

class Array {
    friend int main();
public:
    using   element_t = int;
    typedef size_t index_t;
protected:
    index_t    size;
    element_t* c_array;

    static const char* classname;
    static const char* elementTypename;
public:
    Array(const index_t size) : size(size),c_array(new element_t[size]) {
    }

    Array(const std::initializer_list<element_t>& elements)
            : size(elements.size()),
              c_array(new element_t[size]) {
        int index = 0;
        for (auto& val: elements) {
            c_array[index++] = val;
        }
    }

    ~Array() {
        if (c_array) {
            delete [] c_array;
        }
    }
    Array(const Array& rhs) {
        size    = rhs.size;
        c_array = new element_t[size];
        for (unsigned i=0 ; i<size ; ++i) {
            c_array[i] = rhs.c_array[i];
        }
    }
    Array(Array&& rhs) {
        c_array = rhs.c_array;
        size = rhs.size;
        rhs.c_array = nullptr;
        rhs.size = 0;
    }
    Array& operator=(const Array& rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (c_array) {
            delete [] c_array;
        }
        size = rhs.size;
        c_array = new element_t[size];
        for (unsigned i=0 ; i<size ; ++i) {
            c_array[i] = rhs.c_array[i];
        }
        return *this;
    }
    Array& operator=(Array&& rhs) {
        c_array = rhs.c_array;
        size = rhs.size;
        rhs.c_array = nullptr;
        rhs.size = 0;
        return *this;
    }
    element_t& operator[](index_t idx) {
        return c_array[idx];
    }
    const element_t& operator[](index_t idx) const {
        return c_array[idx];
    }
    index_t getSize() const {
        return size;
    }
    void resize(index_t newSize);
    static std::string nameOfType();
};

inline std::ostream& operator<<(std::ostream& o, const Array& a) {
    o << "[";
    if (a.getSize() > 10) {
        o << "size= " << a.getSize();
    } else {
        for (unsigned i=0 ; i < a.getSize() ; ++i) {
            o << a[i];
            if ( i < a.getSize() - 1) {
                o << " ";
            }
        }
    }
    o << "]";
    return o;
}


#endif
