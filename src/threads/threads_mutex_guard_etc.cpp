#include "test.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <functional>

using namespace std;

class ping_tasks;

void work(unsigned int id, ping_tasks &tasks);


// ---------------- a) -----------------------
// Bitte das folgenden Makro einkommentieren,
// so bald die Unteraufgabe geloest ist
#define A1_a

// enum und state_to_string
enum state {
    todo, ip_inprocess, ip_set, ip_free
};
const string enums[] = {"todo", "ip_inprocess", "ip_set", "ip_free"};

string state_to_string(state s) {
    return enums[s];
}




// ---------------- mine) -----------------------
// Bitte das folgenden Makro einkommentieren,
// so bald die Unteraufgabe geloest ist
#define A1_b

// starte Ping-Prozess, hier simuliert: Rueckgabe wie im Text angegeben
state ping(unsigned int ip) {
    if (ip % 3 == 0) {
        this_thread::sleep_for(1000ms);
        return ip_free;
    } else {
        this_thread::sleep_for(ip * 10ms);
        return ip_set;
    }
}


// Verwaltungsklasse für alle moeglichen IPs
class ping_tasks {

// ---------------- c) -----------------------

    // ctor, Argumente: max ip und ping-Methode
    // ping_tasks(...)

private:
    vector<state> ips;
    function<state(size_t)> ping_f;
    mutex ips_mutex;

public:
    ping_tasks(size_t max_ips, function<state(size_t)> const &f) : ping_f(f) {
        ips.reserve(max_ips);
        for (size_t i = 0; i < max_ips; ++i) {
            ips.push_back(todo);
        }
    }



// ---------------- d) -----------------------
// Bitte das folgenden Makro einkommentieren,
// so bald die Unteraufgabe geloest ist
#define A1_d

    // state operator[] (size_t i) ...
    state operator[](size_t i) {
        return ips[i];
    }

    //size_t num_ips() ...
    size_t size() const {
        return ips.size();
    }


// ---------------- e) -----------------------
// Bitte das folgenden Makro einkommentieren,
// so bald die Unteraufgabe geloest ist
#define A1_e

    // suchen und ping starten: Rueckgabe true=weitersuchen, sonst false=Abbruch
    // thread-safe ip ermitteln, ping aufrufen und Ergebnis sichern

    bool search_and_ping(unsigned int id) {
        bool found = false;
        ips_mutex.lock();
        size_t i;
        for (i = 0; i < ips.size(); ++i) {
            if (ips[i] == todo) {
                found = true;
                ips[i] = ip_inprocess;
                break;
            }
        }
        ips_mutex.unlock();

        if (found) {
            cout << "Thread # " << id << ": ping IP " << i << endl;
            state erg = ping_f(i);
            lock_guard<mutex> guard(ips_mutex);
            ips[i] = erg;
            return true;
        }
        return false;
    }



// ---------------- f) -----------------------
// Bitte das folgenden Makro einkommentieren,
// so bald die Unteraufgabe geloest ist
#define A1_f
//
// Threads starten, Argumente: work-Funktion, id und tasks
// hier threads initialisieren/anlegen/starten

    void start() {
        thread t1(work, 1, ref(*this));
        thread t2(work, 2, ref(*this));
        thread t3(work, 3, ref(*this));

        t1.join();
        t2.join();
        t3.join();

        for (size_t i = 0; i < ips.size(); ++i) {
            cout << "    IP " << i << ": " << state_to_string(ips[i]) << endl;
        }
    }

};

// solange etwas zu tun ist, worker-Methode vorgegeben
void work(unsigned int id, ping_tasks &tasks) {
    cout << "    Thread #" << id << " gestartet" << endl;

    do {} while (tasks.search_and_ping(id));

    cout << "    Thread #" << id << " beendet" << endl;
}

///////////////////////////////////////////////
//// Ab hier beginnt der Testcode,         ////
//// der nicht veraendert werden darf!     ////
//// (hoechstens temporaer zu Testzwecken) ////
///////////////////////////////////////////////


//////////////// a) //////////////////

bool test_A1_a() {
#ifdef A1_a
    state s = todo;
    s = ip_set;
    s = ip_free;
    string t = state_to_string(s);
    return t == "ip_free";
#else
    return false;
#endif
}

//////////////// mine) //////////////////

bool test_A1_b() {
#ifdef A1_b
    bool b1 = (ping(0) == ip_free);
    bool b2 = (ping(1) == ip_set);
    bool b3 = (ping(2) == ip_set);
    bool b4 = (ping(3) == ip_free);
    bool b5 = (ping(4) == ip_set);
    bool b6 = (ping(5) == ip_set);
    return b1 && b2 && b3 && b4 && b5 && b6;
#else
    return false;
#endif
}


///////////////// d) /////////////////

bool test_A1_d() {
#ifdef A1_d
    ping_tasks pt(10, ping);

    bool b1 = pt.size() == 10;
    bool b2 = pt[0] == todo;
    bool b3 = pt[9] == todo;
    return b1 && b2 && b3;
#else
    return false;
#endif
}

//////////////// e) //////////////////

bool test_A1_e() {
#ifdef A1_e
    ping_tasks pt(5, ping);
    pt.search_and_ping(1);
    pt.search_and_ping(1);
    pt.search_and_ping(1);

    return (pt[0] == ip_free &&
            pt[1] == ip_set &&
            pt[2] == ip_set &&
            pt[3] == todo &&
            pt[4] == todo);
#else
    return false;
#endif
}

//////////////// f) //////////////////

bool test_A1_f() {
#ifdef A1_f
    ping_tasks pt(6, ping);
    pt.start();

    return (pt[0] == ip_free &&
            pt[1] == ip_set &&
            pt[2] == ip_set &&
            pt[3] == ip_free &&
            pt[4] == ip_set &&
            pt[5] == ip_set);
#else
    return false;
#endif
}

/////////////// main ////////////////

int main() {
    StartTest(3);
    Assert("a) ", test_A1_a());
    Assert("mine) ", test_A1_b());
    Assert("d) ", test_A1_d());
    Assert("e) ", test_A1_e());
    Assert("f) ", test_A1_f());
    StopTest();
    return EXIT_SUCCESS;
}

