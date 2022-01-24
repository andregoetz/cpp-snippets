#include <iostream>
using namespace std;

void StartTest(unsigned int aufgabe)
{
    cout << endl;
    cout << "--- Probeklausur C++, Aufgabe " << aufgabe << endl;
    cout << "--- Testfälle für Aufgabe " << aufgabe << endl;
}

void Assert(string unteraufgabe, bool result) 
{ 
    cout << "    Test " << unteraufgabe << ": " << ((result) ? "OK" : "FAILED") << endl; 
}

void StopTest()
{
    cout << "--- Fertig" << endl << endl;
}
