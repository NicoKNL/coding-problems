#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    string s;
    cin >> s;

    unordered_map<int, int> m;
    for (char c : s) m[c - '0']++;

    int min_digit = -1;
    int count = INT_MAX;
    for (int i = 0; i < 10; i++) {
        if (m[i] < count || (m[i] == count && min_digit == 0)) {
            count = m[i];
            min_digit = i;
        }
    }

    string result;
    if (min_digit == 0) {
        result = "1";
        loop(i, count) result += '0';
        result += '0';
    } else {
        loop(i, count) result += to_string(min_digit);
        result += to_string(min_digit);
    }
    printf("%s\n", result.c_str());
    return 0;
}