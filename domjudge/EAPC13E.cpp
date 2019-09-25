#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {
        map<string, int> pub1;
        map<string, int> pub2;
        string s;
        int c;
        cin >> c;
        for (int i = 0; i < c; i++) {
            cin >> s;
            pub1[s] = i;
        }

        for (int i = 0; i < c; i++) {
            cin >> s;
            pub2[s] = i;
        }

        vector<string> cipher;
        for (int i = 0; i < c; i++) {
            cin >> cipher[i];
        }

        for (auto entry:pub1) {
            // todo: swap here
        }
    }
    return 0;
}