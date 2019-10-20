#include <bits/stdc++.h>

using namespace std;

int main() {
    long long hashmat, opponent;
    while (cin >> hashmat >> opponent) {
        cout << abs(opponent - hashmat) << endl;
    }
    return 0;
}