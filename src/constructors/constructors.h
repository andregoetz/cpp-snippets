#ifndef CPP_SNIPPETS_CONSTRUCTORS_H
#define CPP_SNIPPETS_CONSTRUCTORS_H

#include <iostream>
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
};

//Special Constructors

class A {
private:
    std::vector<int> _v;

public:
    explicit A(size_t len);

    A(const A &other);

    A(A &&other) noexcept;
};

#endif //CPP_SNIPPETS_CONSTRUCTORS_H