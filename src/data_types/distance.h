#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>

class Distance {
private:
    long double distanceInM;

    friend Distance operator "" _m(long double);

    friend Distance operator "" _km(long double);

    friend Distance operator "" _mile(long double);

    friend Distance operator "" _ft(long double);

    friend Distance operator+(const Distance &lhs, const Distance &rhs);

    explicit Distance(long double distanceInM) : distanceInM(distanceInM) {
#ifdef __DEBUG__
        std::cout << "Distance()" << std::endl;
#endif
    }

public:
    ~Distance() {
#ifdef __DEBUG__
        std::cout << "~Distance()" << std::endl;
#endif
    }

    long double meteres() const;

    long double kiloMeteres() const;

    long double miles() const;

    long double foot() const;

};

inline Distance operator "" _m(long double value) {
    return Distance(value);
}

inline Distance operator "" _km(long double value) {
    return Distance(value * 1000);
}

inline Distance operator "" _mile(long double value) {
    return Distance(value * 1609.344);
}

inline Distance operator "" _ft(long double value) {
    return Distance(value * 0.3048);
}

Distance operator+(const Distance &lhs, const Distance &rhs) {
    return Distance(lhs.distanceInM + rhs.distanceInM);
}

long double Distance::meteres() const {
    return distanceInM;
}

long double Distance::kiloMeteres() const {
    return distanceInM / 1000;
}

long double Distance::miles() const {
    return distanceInM / 1609.344;
}

long double Distance::foot() const {
    return distanceInM / 0.3048;
}

#endif //DISTANCE_H
