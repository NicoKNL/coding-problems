#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    sum = (long long) pow(4, n);
    sum *= (long long) pow(2, n);
    cout << sum << endl;
    return 0;
}