#ifndef CPP_UEBUNGEN_AMPHIBIAN_H
#define CPP_UEBUNGEN_AMPHIBIAN_H

#include "boat.h"
#include "automobile.h"

class Amphibian : public Boat, public Automobile {
public:
    Amphibian(unsigned int _seats, unsigned int _max_v_water, unsigned int _max_v_land) : MeansOfTransport(_seats),
                                                                                          Boat(_max_v_water),
                                                                                          Automobile(_max_v_land) {
        std::cout << "Amphibian()" << std::endl;
    }

    unsigned int getMaxVLand() const {
        return Automobile::getMaxV();
    }

    unsigned int getMaxVWater() const {
        return Boat::getMaxV();
    }
};

#endif //CPP_UEBUNGEN_AMPHIBIAN_H
