#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string clean(string s) {
    string cleaned;
    for (char c: s) {
        c = tolower(c);
        if ('a' <= c && c <= 'z') cleaned += c;
    }
    return cleaned;
}

int main() {
    string s;
    bool palindrome;
    while (getline(cin, s)) {
        if (s == "DONE") break;

        s = clean(s);

        palindrome = true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j && palindrome) {
            if (s.at(i) != s.at(j)) palindrome = false;
            i++;
            j--;
        }

        if (palindrome) {
            cout << "You won't be eaten!" << endl;
        } else {
            cout << "Uh oh.." << endl;
        }
    }
    return 0;
}