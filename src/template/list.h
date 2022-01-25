#ifndef CPP_UEBUNGEN_LIST_H
#define CPP_UEBUNGEN_LIST_H

#include<ostream>
#include<memory>

template<typename T>
class List {
private:
    using value_type = T;

    struct Node {
        value_type data{};

        std::unique_ptr<Node> next;
    };

    int count{};

    std::unique_ptr<Node> root{};

    friend std::ostream &operator<<(std::ostream &out, const List<value_type> &list) {
        out << "[";
        auto *p = &(list.root);
        while (*p != nullptr) {
            out << p->get()->data;
            p = &(p->get()->next);
            if (*p != nullptr) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    //alternative with implementation not in the class --> implementation still needs to be INSIDE the header
//    friend std::ostream &operator<< <value_type>(std::ostream &out, const List<value_type> &list);

public:
    void add(value_type data);

    void clear();
};

//template<typename T>
//std::ostream &operator<<(std::ostream &out, const List<T> &list) {
//    out << "[";
//    auto *p = &(list.root);
//    while (*p != nullptr) {
//        out << p->get()->data;
//        p = &(p->get()->next);
//        if (*p != nullptr) {
//            out << ", ";
//        }
//    }
//    out << "]";
//    return out;
//}

template<typename T>
void List<T>::add(List::value_type data) {
    //überprüfung auf leer ist nicht notwendig, da std::move auch mit einem nullptr funktioniert
    root = std::make_unique<Node>(Node{data, std::move(root)});
    ++count;
}

template<typename T>
void List<T>::clear() {
    root.reset();
    count = 0;
}

#endif //CPP_UEBUNGEN_LIST_H
