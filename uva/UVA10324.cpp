#include <bits/stdc++.h>

using namespace std;

int main() {
    string in;
    int n;
    int casenum = 1;
    while (cin >> in) {
        cin >> n;
        printf("Case %d:\n", casenum);
        int start, end, tmp;
        for (int i = 0; i < n; i++) {
            cin >> start;
            cin >> end;
            if (start > end) {
                tmp = start;
                start = end;
                end = tmp;
            }
            bool valid = true;
            char c = in[start];
            for (int j = start; j <= end; j++) {
                if (in[j] != c) {
                    valid = false;
                }
            }

            if (valid) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        casenum++;
    }
    return 0;
}