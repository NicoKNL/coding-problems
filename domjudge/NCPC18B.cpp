#include <bits/stdc++.h>

using namespace std;

int parse(string s) {
    int result = 0;
    int e = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        result += (s[i] - '0') * e;
        e *= 10;
    }
    return result;
}

int main() {
    int n;
    string s;
    cin >> n;
    int number;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "mumble") continue;
        number = parse(s);
        if (number != i) {
            printf("something is fishy");
            return 0;
        }
    }
    printf("makes sense\n");
    return 0;
}