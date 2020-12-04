#include<bits/stdc++.h>

using namespace std;

map<string, int> values = {
        {"red", 1},
        {"yellow", 2},
        {"green", 3},
        {"brown", 4},
        {"blue", 5},
        {"pink", 6},
        {"black", 7},
};

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int maxval = 0;
    int redcount = 0;
    string s;
    while (n--) {
        cin >> s;
        if (s == "red") {
            redcount++;
        } else {
            sum += values[s];
        }
        maxval = max(maxval, values[s]);
    }

    int max_score = 0;

    if (maxval == 1) {
        max_score = 1;
    } else {
        max_score += maxval * redcount;
        max_score += redcount;
        max_score += sum;
    }
    cout << max_score << endl;

    return 0;
}