#include <bits/stdc++.h>

using namespace std;

int main() {
    string in, out;
    int offset = '1' - '*';
    while (cin >> in) {
        out = "";
        for (char c: in) {
            out += c - offset;
        }
        cout << out << endl;
    }
    return 0;
}