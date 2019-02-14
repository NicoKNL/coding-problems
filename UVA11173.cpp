#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void run() {
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> codes;
    codes.push_back(vector<bool>{0});
    codes.push_back(vector<bool>{1});

    while (codes.at(0).size() < n) {
        for (int i = codes.size() - 1; i >= 0; i--) {
            codes.push_back(codes.at(i));
        }

        for (int i = 0; i < codes.size(); i++) {
            if (i < codes.size() / 2) codes.at(i).insert(codes.at(i).begin(), 0);
            else codes.at(i).insert(codes.at(i).begin(), 1);
        }
    }

    long result = 0;
    for (int i = 0; i < n; i++) {
        result += (1 << (n-i-1)) * codes.at(k).at(i);
    }

    cout << result << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}
