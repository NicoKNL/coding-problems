#include <bits/stdc++.h>

using namespace std;
// Todo: finish
int main() {
    int r, c, buttons, length;
    cin >> r >> c >> length;

    buttons = r * c;
    long long modul = 1000000007;
    long long ans = 1;
    long long tmp;
    while (length--) {
        ans *= buttons;
        ans %= modul;
    }
    cout << ans << endl;
    return 0;
}