#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


#define loop(var, n) for (int var = 0; var < n; var++)

int main() {
    int b, s;
    int cases = 1;
    while (cin >> b >> s) {
        if (b == 0 && s == 0) break;

        vector<int> bachelors(b);
        vector<int> spinsters(s);

        loop(i, b) cin >> bachelors[i];
        loop(i, s) cin >> spinsters[i];

        if (s >= b) {
            printf("Case %d: 0\n", cases);

        } else {
            sort(bachelors.begin(), bachelors.end());
            printf("Case %d: %d %d\n", cases, b-s, bachelors[0]);
        }

        cases++;
    }
    return 0;
}