#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        switch(tmp) {
            case 1:
                cin >> tmp;
                s.insert(tmp);
                break;
            case 2:
                cin >> tmp;
                s.erase(tmp);
                break;
            case 3:
                cin >> tmp;
                set<int>::iterator itr=s.find(tmp);
                if (itr != s.end()) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
                break;
        }
    }
    return 0;
}



