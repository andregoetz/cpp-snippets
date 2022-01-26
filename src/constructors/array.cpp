#include "array.h"

const char *Array::classname = "Array";
const char *Array::elementTypename = "int";


void Array::resize(index_t newSize) {
    element_t *new_c_carray = new element_t[newSize];
    if (new_c_carray) {
        if (c_array != nullptr) {
            for (index_t i = 0; i < newSize; ++i) {
                new_c_carray[i] = i < size ? c_array[i] : 0;
            }
            delete[] c_array;
        }
        c_array = new_c_carray;
        size = newSize;
    }
}

std::string Array::nameOfType() {
    return std::string(classname) + " of " + elementTypename;
}
