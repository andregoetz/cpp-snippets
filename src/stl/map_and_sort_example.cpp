#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
using MapIterator = map<string, size_t>::iterator;

bool is_name(const string &str) {
    if (!isalpha(str[0]) && !str.starts_with('_')) { //muss mit Buchstabe anfangen, '_' ist auch ein Buchstabe!
        return false;
    }
    for (size_t i = 1; i < str.size(); ++i) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && (str[i] != '_')) {
            return false;
        }
    }
    return true;
}

bool cmp_fun(MapIterator &a, MapIterator &b) {
    return a->second < b->second;
}

class cmp_obj {
public:
    bool operator()(MapIterator &a, MapIterator &b) {
        return a->second < b->second;
    }
};

int main() {
    cout << "Alle Variablennamen"s << endl;
    map<string, size_t> var_names;
    ifstream file("../data/names.txt");
    while (file.is_open()) {
        string str;
        file >> str;
        if (str.empty()) {
            file.close();
        } else {
            if (is_name(str)) {
                var_names[str]++;
            }
        }
    }
    for (const auto &i: var_names) {
        cout << i.first << ", "s << i.second << endl;
    }

    cout << endl;

    cout << "Alle Variablennamen sortiert mit Funktion"s << endl;
    vector<MapIterator> sorted_names_fun;
    for (auto i = var_names.begin(); i != var_names.end(); i++) {
        sorted_names_fun.push_back(i);
    }
    sort(sorted_names_fun.begin(), sorted_names_fun.end(), cmp_fun);
    for (const auto &i: sorted_names_fun) {
        cout << i->first << ", "s << i->second << endl;
    }

    cout << endl;

    cout << "Alle Variablennamen sortiert mit Funktor"s << endl;
    vector<MapIterator> sorted_names_obj;
    for (auto i = var_names.begin(); i != var_names.end(); i++) {
        sorted_names_obj.push_back(i);
    }
    sort(sorted_names_obj.begin(), sorted_names_obj.end(), cmp_obj());
    for (const auto &i: sorted_names_obj) {
        cout << i->first << ", "s << i->second << endl;
    }

    cout << endl;

    cout << "Alle Variablennamen mit Häufigkeit >= 10"s << endl;
    for (const auto &i: var_names) {
        if (i.second >= 10) {
            cout << i.first << ", "s << i.second << endl;
        }
    }

    cout << endl;

    cout << "Anzahl der Wörter die mehr als einmal vorkommen: "s;
    cout << count_if(var_names.begin(), var_names.end(), [](auto i) { return i.second > 1; });
    cout << endl;
    return 0;
}
