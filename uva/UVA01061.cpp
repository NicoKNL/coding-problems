#include <bits/stdc++.h>
using namespace std;

// todo: finish

map<string, string> abomap = {
        {"A", "AA"},
        {"AB", "AB"},
        {"A", "AO"},
//        {"B", "BB"},
//        {"B", "BO"},
        {"O", "OO"},

};

map<string, string> typemap = {
        {"AA", "A"},
        {"AB", "AB"},
        {"AO", "A"},
        {"BB", "B"},
        {"BO", "B"},
        {"OO", "O"},
};

vector<string> childTypeFinder(string p1, string p2) {
    set<string> T;
    string tmp;
    for (char c1 : p1) {
        for (char c2 : p2) {
            tmp = c1 + c2;
            T.insert(typemap[tmp]);
        }
    }

    vector<string> result(T.size());
    copy(T.begin(), T.end(), result.begin());
    return result;
}

int main() {
    string p1, p2, c, tmp;
    int cases = 1;
    while (cin >> p1 >> p2 >> c) {
        if (p1 == "E") break;
        bool swapped = false;
        if (p1 == "?") {
            tmp = p2;
            p2 = "?";
            p1 = tmp;
            swapped = true;
        }

        if (c == "?") {
            char rh1 = p1[p1.size()-1];
            char rh2 = p2[p2.size()-1];

            string abo1 = p1.substr(0, p1.size() - 1);
            string abo2 = p2.substr(0, p2.size() - 1);
            if (abomap.find(abo1) != abomap.end()) {
                abo1 = abomap[abo1];
            } else { // B
                //...
            }

            if (abomap.find(abo2) != abomap.end()) {
                abo2 = abomap[abo2];
            } else { // B
                //...
            }

            vector<string> childtypes = childTypeFinder(abo1, abo2);

            if (rh1 == '-' && rh2 == '-') {

            }

        } else { // p2 == "?"

        }

        if (swapped) {
            tmp = p1;
            p1 = p2;
            p2 = tmp;
        }

        printf("Case %d: ", cases);
        printf("%s %s %s\n", p1.c_str(), p2.c_str(), c.c_str());
        cases++;
    }
    return 0;
}