#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int start = 0;
    int tmp, len;
    while (n--) {
        cin >> tmp >> len;
        start += tmp;
    }
    cout << s.substr(start, len);
    return 0;
}