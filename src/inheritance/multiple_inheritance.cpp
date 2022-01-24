#include <iostream>
#include <memory>

#include "amphibian.h"

using namespace std;

int main() {
    auto amphibian = make_unique<Amphibian>(2, 3, 4);
    cout << amphibian->getSeats() << endl;
    cout << amphibian->getMaxVWater() << endl;
    cout << amphibian->getMaxVLand() << endl;
    return 0;
}
