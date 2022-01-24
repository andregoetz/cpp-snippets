#include <iostream>
#include <thread>

using namespace std;

int main() {
    thread first([] {
        cout << "Thread 1 started" << endl;
        this_thread::sleep_for(1000ms);
        cout << "Thread 1 beendet sich" << endl;
    });
    thread second([] {
        cout << "Thread 2 started" << endl;
        this_thread::sleep_for(2000ms);
        cout << "Thread 2 beendet sich" << endl;
    });
    thread third([] {
        cout << "Thread 3 started" << endl;
        this_thread::sleep_for(3000ms);
        cout << "Thread 3 beendet sich" << endl;
    });

    first.join();
    second.join();
    third.join();
    return 0;
}
