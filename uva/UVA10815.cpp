#include <bits/stdc++.h>

using namespace std;

vector<string> clean(string s) {
    vector<string> result;
    string cleaned;
    for (char c: s) {
        c = tolower(c);
        if ('a' <= c && c <= 'z') cleaned += c;
        else {
            if (cleaned != "") {
                result.push_back(cleaned);
                cleaned = "";
            }
        }
    }
    if (cleaned != "") {
        result.push_back(cleaned);
        cleaned = "";
    }
    return result;
}

int main() {
    string s;
    set<string> dict;
    while (cin >> s) {
        vector<string> cleaned = clean(s);
        for (string clean : cleaned) dict.insert(clean);
    }

    for (auto ds : dict) {
        cout << ds << endl;
    }
}