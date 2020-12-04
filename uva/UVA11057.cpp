#include <bits/stdc++.h>

#define loop(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    while (cin >> n) {
        vi books(n);
        loop(i, n) cin >> books[i];
        sort(books.begin(), books.end());

        int target;
        cin >> target;

        vi half(n);
        loop(i, n) half[i] = target - books[i];

        vii pairs;
        loop(a, n) {
            if (half[a] == 0) continue;
            int tmp = books[a];
            books[a] = -1;
            auto b = lower_bound(books.begin(), books.end(), half[a]);
            int val_b = books[b - books.begin()];
            if (half[a] == val_b) pairs.push_back(make_pair(min(tmp, val_b), max(tmp, val_b)));
            books[a] = tmp;
        }

        int i;
        int j;
        int diff = INT_MAX;
        loop(k, pairs.size()) {
            if (pairs[k].second - pairs[k].first < diff) {
                diff = pairs[k].second - pairs[k].first;
                j = pairs[k].second;
                i = pairs[k].first;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
    }
    return 0;
}
