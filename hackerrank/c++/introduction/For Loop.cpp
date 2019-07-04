#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string sanitize(string s) {
    if (s[s.length() - 1] == '>') {
        s = s.substr(1, s.length() - 3);
    } else {
        s = s.substr(1, s.length() - 2);
    }

    return s;
}

string parentPrefix(string prefix) {
    int last_dot;
    for (int i = 0; i < prefix.length(); i++) {
        if (prefix[i] == '.') {
            last_dot = i;
        }
    }
    return prefix.substr(0, last_dot);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    string tmp;
    string name, attr, value;
    string prefix;
    map<string, map<string, string>> tags;
    while(n--) {
        cin >> tmp;
        if (tmp[1] != '/') {
            name = tmp.substr(1);
            value = tmp;
            map<string, string> tmp_map;

            int attr_count = 0;
            while (value[value.length() - 1] != '>') {
                cin >> attr >> tmp >> value;
                tmp_map[attr] = sanitize(value);
                attr_count++;
            }

            if (attr_count > 0) {
                prefix = prefix + "." + name;
            } else {
                prefix = prefix + "." + name.substr(0, name.length() - 1); // Chop '>'
            }

            tags[prefix] = tmp_map;
        } else {
            prefix = parentPrefix(prefix);
        }
    }

    while(q--) {
        cin >> tmp;
        int tilde = -1;
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] == '\~') {
                tilde = i;
            }
        }

        name = "." + tmp.substr(0, tilde);
        attr = tmp.substr(tilde + 1);

        if (tilde == -1) {
            cout << "Not Found!\n";
        } else if (tags.find(name) == tags.end()) {
            cout << "Not Found!\n";
        } else {
            if (tags[name].find(attr) == tags[name].end()) {
                cout << "Not Found!\n";
            } else {
                cout << tags[name][attr] << endl;
            }
        }
    }
    return 0;
}
