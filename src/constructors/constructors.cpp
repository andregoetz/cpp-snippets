#include "constructors.h"

OneAttribute::OneAttribute() : num(5) {}

OneAttribute::OneAttribute(int num) : num(num) {}

TwoAttribute::TwoAttribute(int _a, int _b) : a(_a), b(_b) {}


A::A(size_t len) {
    _v.reserve(len);
    std::cout << "Explicit-Constructor" << std::endl;
}

A::A(const A &other) : _v(other._v) {
    std::cout << "Copy-Constructor" << std::endl;
}

A::A(A &&other) noexcept: _v(std::move(other._v)) {
    std::cout << "Move-Constructor" << std::endl;
}