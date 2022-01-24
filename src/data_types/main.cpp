#include <iostream>
#include "distance.h"

using namespace std;

int main() {
    cout << "Distanz 1km:" << endl;
    Distance distanceKm(1.0_km);
    cout << distanceKm.meteres() << endl;
    cout << distanceKm.kiloMeteres() << endl;
    cout << distanceKm.foot() << endl;
    cout << distanceKm.miles() << endl;

    cout << endl;

    cout << "Distanz 1m:" << endl;
    Distance distanceM(1.0_m);
    cout << distanceM.meteres() << endl;
    cout << distanceM.kiloMeteres() << endl;
    cout << distanceM.foot() << endl;
    cout << distanceM.miles() << endl;

    cout << endl;

    cout << "Distanz 1mile:" << endl;
    Distance distanceMile(1.0_mile);
    cout << distanceMile.meteres() << endl;
    cout << distanceMile.kiloMeteres() << endl;
    cout << distanceMile.foot() << endl;
    cout << distanceMile.miles() << endl;

    cout << endl;

    cout << "Distanz 1ft:" << endl;
    Distance distanceFt(1.0_ft);
    cout << distanceFt.meteres() << endl;
    cout << distanceFt.kiloMeteres() << endl;
    cout << distanceFt.foot() << endl;
    cout << distanceFt.miles() << endl;

    cout << endl;

    cout << "Addition:" << endl;
    Distance distance1(42000.0_m);
    Distance distance2(69.0_m);
    Distance result = distance1 + distance2;
    cout << result.meteres() << endl;
    return 0;
}
