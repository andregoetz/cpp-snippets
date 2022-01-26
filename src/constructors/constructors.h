#ifndef CPP_SNIPPETS_CONSTRUCTORS_H
#define CPP_SNIPPETS_CONSTRUCTORS_H

#include <iostream>
#include <initializer_list>
#include <vector>

//Attributes and methods are public in struct
struct OneAttribute {
    int num;

    OneAttribute();

    OneAttribute(int num);
};

struct TwoAttribute {
    int a;
    int b;

    TwoAttribute(int _a = 1, int _b = 2);

    TwoAttribute(const std::initializer_list<int>& elements);
};

//Special Constructors

class A {
private:
    std::vector<int> _v;

public:
    explicit A(size_t len);

    A(const A &other);

    A(A &&other) noexcept;

    //const behind method name -> method can be used on const Objects
    void andreas() const{}
};

#endif //CPP_SNIPPETS_CONSTRUCTORS_H
