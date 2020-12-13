#include <bits/stdc++.h>

using namespace std;

int main() {
    double cost;
    cin >> cost;
    
    int n;
    cin >> n;
    double area = 0;
    double a, b;
    while (n--) {
        cin >> a >> b;
        area += a * b;
    }
    cout << fixed << setprecision(9) << area * cost << endl;
    return 0;
}