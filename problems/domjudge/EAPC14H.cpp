#include <bits/stdc++.h>

using namespace std;
// todo: WA
int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n, selected, favs;
        cin >> n >> selected >> favs;
        vector<int> candidates(n);
        vector<int> favpoints(favs);
        for (int i = 0; i < favs; i++) {
            cin >> favpoints[i];
        }

        vector<int> otherpoints(n-favs);
        for (int i = 0; i < n - favs; i++) {
            cin >> otherpoints[i];
        }



        int stickers;
        cin >> stickers;
        vector<int> points(stickers);
        for (int i = 0; i < stickers; i++) {
            cin >> points[i];
        }

        sort(otherpoints.begin(), otherpoints.end());

        int ST = 0;
        int tmp;

        vector<bool> sel(stickers);

        if (stickers > favpoints.size()) {
            for (int i = 0; i < stickers - favpoints.size(); i++) {
                sel[i] = true;
                otherpoints[i] += points[i];
                ST++;
            }
            sort(otherpoints.begin(), otherpoints.end());
        }

        sort(favpoints.begin(), favpoints.end());
        int end = otherpoints.size() - 1;
        bool found = false;
        for (int i = favpoints.size() - 1; i >= 0 && ST < stickers; i--) {
            found = false;
            while (!found && end >= 0) {
                for (int j = ST; j < stickers; j++) {
                    if (sel[j] == false) {
                        if (favpoints[i] + points[j] >= otherpoints[end]) {
                            sel[j] = true;
                            favpoints[i] += points[j];
                            ST++;
                            found = true;
                            break;
                        }
                    } else {
                        continue;
                    }
                }
                end--;
            }
        }

        int count = 0;
        int i = otherpoints.size() - 1;
        int j = favpoints.size() - 1;
        while (selected > 0) {
            if (i >= 0 && j >= 0) {
                if (favpoints[j] >= otherpoints[i]) {
                    count++;
                    selected--;
                    j--;
                } else {
                    selected--;
                    i--;
                }
            } else {
                if (i >= 0) {
                    break;
                } else {
                    count++;
                    selected--;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}

/*
3
6 2 4
23 29 37 47
71 83
4
10 20 30 50
5 3 3
40 60 80
85 85
4
10 20 30 50
6 3 3
14 15 92
65 35 89
4
10 20 30 50
 */