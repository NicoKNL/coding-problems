#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    bool first = true;
    while (cin >> n) {
        if (!first) cout << endl;
        else first = false;
        unordered_map<string, int> umap;
        vector<string> names;
        string s, t;
        for (int i = 0; i < n; i++) {
            cin >> s;
            umap[s] = 0;
            names.push_back(s);
        }

        int money, people, rest;
        for (int i = 0; i < n; i++) {
            cin >> s >> money >> people;
            for (int j = 0; j < people; j++) {
                cin >> t;
                umap[t] += money / people;
            }
            if (people > 0) {
                rest = money % people;
                umap[s] += rest - money;
            }
        }

        for (string name: names) {
            cout << name << " " << umap[name] << endl;
        }
    }
    return 0;
}