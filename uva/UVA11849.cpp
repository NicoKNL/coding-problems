#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, tmp;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        set<int> jack;
        set<int> jill;
        set<int> intersect;
        while (n--){
            cin >> tmp;
            jack.insert(tmp);
        }

        while (m--) {
            cin >> tmp;
            jill.insert(tmp);
        }

        set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), inserter(intersect, intersect.begin()));
        cout << intersect.size() << endl;
    }
    return 0;
}