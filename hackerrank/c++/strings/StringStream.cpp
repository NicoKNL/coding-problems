#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    int a;
    char c;
    bool number = true;
    vector<int> result;
    while (ss) {
        if (number) {
            ss >> a;
            result.push_back(a);
        } else {
            ss >> c;
        }
        number = !number;
    }

    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}