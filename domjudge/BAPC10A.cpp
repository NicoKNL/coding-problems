#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int seq;
        cin >> seq;
        vector<int> seqA(seq);
        vector<int> seqB(seq);
        vector<bool> counter(seq);
        set<int> A;
        set<int> B;
        vector<pair<int, int>> result;
        for (int i = 0; i < seq; i++) {
            cin >> seqA[i];
        }
        for (int i = 0; i < seq; i++) {
            cin >> seqB[i];
        }
        int i = 1;
        int j = 1;
        int mismatches = 0;
        for (int k = 0; k < seq; k++) {
            if (counter[seqA[k]]) {
                mismatches--;
            } else {
                counter[seqA[k]] = true;
                mismatches++;
            }

            if (counter[seqB[k]]) {
                mismatches--;
            } else {
                mismatches++;
                counter[seqB[k]] = true;
            }

            if (mismatches == 0) {
                result.push_back(make_pair(i, j));
                j++;
                i = j;
            } else {
                j++;
            }
        }

        for (int i = 0; i < result.size(); i++) {
            cout << result[i].first << "-" << result[i].second;
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}