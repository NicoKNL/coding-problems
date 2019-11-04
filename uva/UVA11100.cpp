#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int cases = 1;
    while (cin >> n) {
        if (n == 0) break;
        if (cases > 1) {cout << endl;}
        vector<int> bags(n);
        for (int i = 0; i < n; i++) {
            cin >> bags[i];
        }
        sort(bags.begin(), bags.end());

        int max_counter = -1;
        int counter = -1;
        int current;
        int max_current;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                current = bags[0];
                counter = 1;
                max_counter = 1;
                max_current = current;
            } else {
                if (bags[i] == current) {
                    counter++;
                } else {
                    current = bags[i];
                    counter = 1;
                }
                if (counter > max_counter) {
                    max_counter = counter;
                    max_current = current;
                }
            }
        }

        int max_packs = max_counter;
        vector<bool> taken(n);
        vector<vector<int>> packs;

        // put all items into bag
        int tracker = -1;
        for (int i = 0; i < n; i++) {
            if (bags[i] == max_current && !taken[i]) {
                if (tracker == -1) tracker = i;
                packs.push_back(vector<int> {bags[i]});
                taken[i] = true;
            }
        }

        bags.erase(bags.begin() + tracker, bags.begin() + tracker + max_counter);

        int p = 0;
        for (int i = 0; i < bags.size(); i++) {
            packs[p].push_back(bags[i]);
            p = (p + 1) % max_counter;
        }

        for (int i = 0; i < packs.size(); i++) {
            sort(packs[i].begin(), packs[i].end());
        }

        cout << packs.size() << endl;
        for (vector<int> p : packs) {
            for (int i = 0; i < p.size(); i++) {
                if (i > 0) cout << " ";
                cout << p[i];
            }
            cout << endl;
        }
        cases++;
    }
    return 0;
}