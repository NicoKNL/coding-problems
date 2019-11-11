#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define loop(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    while (n--) {
        int days, parties;
        cin >> days >> parties;
        vector<bool> calendar(days);
        int hartal;
        loop(i, parties) {
            cin >> hartal;
            loop(j, days) {
                if ((j + 1) % hartal == 0 && (j % 7 != 5 && j % 7 != 6))
                    calendar[j] = true;
            }
        }
        int hartalsum = 0;
        loop(i, days) hartalsum += calendar[i];

        cout << hartalsum << endl;

    }
    return 0;
}