#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        map<char, int> ma;
        map<char, int> mb;
//        printf("[%s] [%s]:\n", a.c_str(), b.c_str());
        for (char c : a) ma[c]++;
        for (char c : b) mb[c]++;

        string result;
        for (auto entry : ma) {
            char c = entry.first;
            int counta = entry.second;
            int countb = mb[c];
            for (int i = 0; i < min(counta, countb); i++) {
                result += c;
            }
        }
        sort(result.begin(), result.end());
        printf("%s\n", result.c_str());
    }
    return 0;
}