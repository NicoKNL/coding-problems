#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    stringstream ss;
    string line;

    getline(cin, line);
    ss.str(line); ss.clear();

    int cases;
    ss >> cases;
    int n = 1;
    while (cases--) {
        if (n > 1) cout << endl;
        getline(cin, line); // empty line
        getline(cin, line);
        ss.str(line); ss.clear();
        vi index_arr;
        int tmp;
        while (ss >> tmp) {
            index_arr.push_back(tmp);
        }

        getline(cin, line);
        ss.str(line); ss.clear();

        vector<string> value_arr;
        string tmpd;
        while (ss >> tmpd) {
            value_arr.push_back(tmpd);
        }

        vector<string> result(value_arr.size());
        loop(i, index_arr.size()) {
            result[index_arr[i]-1] = value_arr[i];
        }

        for (auto v : result) {
            cout << v << endl;
        }
        n++;
    }
    return 0;
}