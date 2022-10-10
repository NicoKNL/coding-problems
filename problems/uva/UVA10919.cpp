#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int cats;
        cin >> cats;

        vi courses(n);
        vvi full_req(cats);
        for (int i = 0; i < n; i++) {
            cin >> courses[i];
        }

        vi req(cats);
        for (int i = 0; i < cats; i++) {
            int j;
            cin >> j >> req[i];
            int course_num;
            for (int k = 0; k < j; k++) {
                cin >> course_num;
                full_req[i].push_back(course_num);
            }
        }

        for (int course : courses) {
            for (int i = 0; i < cats; i++) {
                bool found = false;
                for (int j = 0; j < full_req[i].size() && !found; j++) {
                    if (course == full_req[i][j]) {
                        req[i]--;
                        found = true;
                    }
                }
            }
        }

        bool possible = true;
        for (int i = 0; i < cats; i++) {
            if (req[i] > 0) possible = false;
        }

        if (possible) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}