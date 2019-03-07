#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, c, tmp, d, k;
    cin >> n;
    cin.ignore();
    while (n--) {
        cin >> c;
        vector<int> coeff;
        for (int i = 0; i <= c; i++) {
            cin >> tmp;
            coeff.push_back(tmp);
        }
        cin >> d >> k;
        cin.ignore();
        long a = 0;
        int index = 0;
        int digit = 0;
        while (index < k) {
            digit++;
            for (int i = 0; i < d * digit; i++) {
                index++;
            }
        }

        for (int i = 0; i < coeff.size(); i++) {
            a += coeff[i] * (long) pow((double) digit, (double) i);
        }
        cout << a << endl;
    }
    return 0;
}