#include<bits/stdc++.h>
using namespace std;
typedef vector<char> vc;

int main() {
    string s;
    int cases = 1;
    while (getline(cin, s)) {
        if (s == "end") break;
        map<char, int> counter;
        for (char c : s) counter.find(c) != counter.end() ? counter[c]++ : counter[c] = 1;

        vc stacks;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (stacks.size() == 0) {
                counter[c]--;
                stacks.push_back(c);
            } else {
                bool found = false;
                for (int j = 0; j < stacks.size() && !found; j++) {
                    char top = stacks[j];
                    if (c == top) {
                        counter[c]--;
                        found = true;
                    }
                }

                for (int j = 0; j < stacks.size() && !found; j++) {
                    char top = stacks[j];
                    if (c < top) {
                        counter[c]--;
                        stacks[j] = c;
                        found = true;
                    }
                }

                if (!found) {
                    counter[c]--;
                    stacks.push_back(c);
                }
            }
        }
        printf("Case %d: %d\n", cases, stacks.size());
        cases++;
    }
    return 0;
}