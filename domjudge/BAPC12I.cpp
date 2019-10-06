#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string commands;
        cin >> commands;
        int length;
        cin >> length;
        list<string> muh_list;
        string scanner;
        cin >> scanner;
        int start = 1;
        int size = 1;
        string tmp;
        for (int i = 1; i < scanner.length() - 1;i++) {
            if (scanner.at(i) == ',') {
                tmp = scanner.substr(start, size);
                muh_list.emplace_back(tmp);
                start = i + 1;
                size = 1;
            }
        }
        if (!tmp.empty()) {
            tmp = scanner.substr(start, size);
            muh_list.emplace_back(tmp);
        }
        bool front = true;
        bool error = false;
        for (char c : commands) {
            if (c == 'R') front = !front;
            if (c == 'D') {
                if (muh_list.size() == 0) {
                    cout << "error" << endl;
                    error = true;
                    break;
                }
                if (front) {
                    muh_list.pop_front();
                } else {
                    muh_list.pop_back();
                }
            }
        }

        if (!error) {
            cout << "[";
            int i = 0;
            if (!front) {
                muh_list.reverse();
            }
            for (auto s : muh_list) {
                cout << s;
                if (i < muh_list.size() - 1) {
                    cout << ",";
                }
                i++;
            }
            cout << "]" << endl;
        }
    }
    return 0;
};