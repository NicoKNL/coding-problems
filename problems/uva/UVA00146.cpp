#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, s_first;

    while (true) {
        cin >> s;
        if (s == "#") break;

        s_first = s;
        sort(s_first.begin(), s_first.end());
        next_permutation(s.begin(), s.end());
        if (s == s_first) {
            cout << "No Successor" << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}