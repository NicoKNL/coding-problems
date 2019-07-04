#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n, tmp;
    string s;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        switch(tmp) {
            case 1:
                cin >> s >> tmp;
                if (m.find(s) == m.end()) {
                    m.insert(make_pair(s, tmp));
                } else {
                    m[s] += tmp;
                }
                break;
            case 2:
                cin >> s;
                m.erase(s);
                break;
            case 3:
                cin >> s;
                if (m.find(s) == m.end()) {
                    cout << 0 << endl;
                } else {
                    cout << m.at(s) << endl;
                }
                break;
        }
    }
    return 0;
}



