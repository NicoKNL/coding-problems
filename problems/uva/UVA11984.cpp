#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    int cases = 1;
    cin >> n;
    while (n--) {
        double celsius, increase;
        cin >> celsius >> increase;
        double fahrenheit = 9.0 / 5.0 * celsius + 32.0;
        fahrenheit += increase;

        celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

        printf("Case %d: %.2f\n", cases, celsius);
        cases++;
    }

    return 0;
}