#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
    int n, t, sum, tmp, count;
    vi sales;
    cin >> n;
    while (n--) {
        cin >> t;
        sum = 0;
        sales.clear();
        for (int i = 0; i < t; i++) {
            cin >> tmp;
            sales.push_back(tmp);
            count = 0;
            if (i > 0) {
                for (int j = 0; j < i; j++) {
                    if (sales[j] <= tmp) count++;
                }
            }
            sum += count;
        }
        cout << sum << endl;
    }
    return 0;
};