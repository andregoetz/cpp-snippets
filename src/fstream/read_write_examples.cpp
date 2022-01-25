#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read_without_getline() {
    ifstream file("../data/names.txt");
    while (file.is_open()) {
        string str;
        file >> str; //file >> noskipws >> str --> for not skipping whitespaces
        if (str.empty()) {
            file.close();
        } else {
            cout << str << " ";
        }
    }
    cout << endl;
}

vector<string> read_all_lines(const string &filepath) {
    vector<string> lines;
    ifstream file(filepath);
//    noskipws(file); //s. line 12
    if (!file) {
        throw "Datei " + filepath + " nicht gefunden!";
    }
    for (string line; getline(file, line);) {
        lines.push_back(line);
    }
    return lines;
}

void write_all_lines(const string &filepath, const vector<string> &lines) {
    ofstream file(filepath);
    for (const string &l: lines) {
        file << l << endl;
    }
}

int main() {
    auto lines = read_all_lines("../data/input.txt");
    for (const string &l: lines) {
        cout << l << endl;
    }
    write_all_lines("../data/output.txt", lines);
    try {
        read_all_lines("ERROR_FILE");
    } catch (const string &fnfe) {
        cout << "Error: " << fnfe << endl;
    }

    read_without_getline();
    return 0;
}
