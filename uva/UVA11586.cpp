#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define loop(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s); // \n
    while (n--) {
        int mf = 0;
        int ff = 0;
        int mm = 0;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        int count = 0;
        while (ss >> tmp){
            count++;
            if (tmp[0] != tmp[1]) mf++;
            else if (tmp[0] == 'F') ff++;
            else mm++;
        }

        if (count == 1 || ff != mm) {
            printf("NO LOOP\n");
        } else {
            printf("LOOP\n");
        }
    }
    return 0;
}