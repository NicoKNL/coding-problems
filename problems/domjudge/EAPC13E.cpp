#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {
        int strings;
        cin >> strings;
        string s;
        string tmp;
        map<string, int> key1;
        map<string, int> key2;
        for (int i = 0; i < strings; i++) {
            cin >> s;
            key1[s] = i;
        }

        for (int i = 0; i < strings; i++) {
            cin >> s;
            key2[s] = i;
        }

        vector<string> cipher(strings);
        for (int i = 0; i < strings; i++) {
            cin >> cipher[i];
        }

        vector<string> result(strings);
        for (auto entry : key1) {
            result[entry.second] = cipher[key2[entry.first]];
        }

        for (int i = 0; i < strings; i++) {
            cout << result[i];
            if (i < strings - 1) {
                cout << " ";
            }
        }
        cout << endl;


    }
    return 0;
}