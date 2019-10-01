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
        int sumA = 0;
        int sumB = 0;
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
        for (int k = 0; k < seq; k++) {
            A.insert(seqA[k]);
            B.insert(seqB[k]);
            sumA += seqA[k];
            sumB += seqB[k];
            if (sumA == sumB) { // potentially equal
                if (A == B) { // O(n) check
                    result.push_back(make_pair(i, j));
                    j++;
                    i = j;
                }
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