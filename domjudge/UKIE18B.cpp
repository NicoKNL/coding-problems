#include <bits/stdc++.h>

using namespace std;

int main() {
    int home, busses, stops;
    cin >> home >> busses >> stops;
    vector<string> stopdata(busses);
    for (int i = 0; i < busses; i++) {
        cin >> stopdata[i];
    }

    int left, right;
    if (home > 1) {
        left = home - 1;
    } else {
        left = stops;
    }

    if (home < stops) {
        right = home + 1;
    } else {
        right = 1;
    }

    int count = 0;
    for (string s : stopdata) {
        if (s.at(left - 1) == '1') count++;
        if (s.at(right - 1) == '1') count++;
    }
    cout << count << endl;
    return 0;
}