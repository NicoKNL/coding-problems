#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define loop(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string s;
        getline(cin, s); // \n
        int shortest, longest, count, sum = 0;
        loop(i, n) {
            getline(cin, s);
            count = 0;
            for (char c : s) {
                if (c == ' ') count++;
            }
            sum += count;
            if (i == 0) {
                shortest = longest = count;
            } else {
                shortest = min(shortest, count);
                longest = max(longest, count);
            }
        }
        cout << sum - shortest * n << endl;
    }
    return 0;
}