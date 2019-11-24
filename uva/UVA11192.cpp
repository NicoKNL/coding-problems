#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int G;
    while (cin >> G) {
        if (G == 0) break;
        string s;
        cin >> s;
        int L = s.length() / G;
        int start = 0;
        while (start < s.length()) {
            reverse(s.begin() + start, s.begin() + start + L);
            start += L;
        }
        cout << s << endl;
    }
    return 0;
}