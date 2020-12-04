#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string per = "PER";
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != per[i%3]) counter++;
    }
    cout << counter << endl;
    return 0;
}