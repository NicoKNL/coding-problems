#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        list<char> beiju;
        auto it = beiju.begin();
        for (char c: s) {
            if (c == '[') {
                it = beiju.begin();
            }
            else if (c == ']'){
                it = beiju.end();
            }
            else {
                it = beiju.insert(it, c);
                it++;
            }
        }

        for (char c: beiju) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}