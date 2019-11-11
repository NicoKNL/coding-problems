#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    map<string, int> conquest;
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        string country;
        ss >> country;
        if (conquest.find(country) != conquest.end()) {
            conquest[country]++;
        } else {
            conquest[country] = 1;
        }
    }

    for (auto entry : conquest) {
        cout << entry.first << " " << entry.second << endl;
    }
    return 0;
}