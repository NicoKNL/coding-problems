#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool AaZzComp(char c1, char c2) {
    bool same_char = c1 == c2;
    bool same_letter = tolower(c1) == tolower(c2);
    if (same_char) {
        return false;
    } else if (same_letter) {
        return c1 < c2;
    } else {
        return tolower(c1) < tolower(c2);
    }
}

int main() {
    int n;
    string s;

    cin >> n;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end(), AaZzComp);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), AaZzComp));
    }
    return 0;
}