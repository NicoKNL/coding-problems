#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

map<char, char> m = {
        {'1', '`'},{'2', '1'},{'3', '2'},{'4', '3'},
        {'5', '4'},{'6', '5'},{'7', '6'},{'8', '7'},
        {'9', '8'},{'0', '9'},{'-', '0'},{'=', '-'},

        {'W', 'Q'},{'E', 'W'},{'R', 'E'},{'T', 'R'},
        {'Y', 'T'},{'U', 'Y'},{'I', 'U'},{'O', 'I'},
        {'P', 'O'},{'[', 'P'},{']', '['},{'\\', ']'},

        {'S', 'A'},{'D', 'S'},{'F', 'D'},{'G', 'F'},{'H', 'G'},
        {'J', 'H'},{'K', 'J'},{'L', 'K'},{';', 'L'},{'\'', ';'},

        {'X', 'Z'},{'C', 'X'},{'V', 'C'},
        {'B', 'V'},{'N', 'B'},{'M', 'N'},
        {',', 'M'},{'.', ','},{'/', '.'},
};

int main() {
    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            if (m.find(c) != m.end()) cout << m[c];
            else cout << c;
        }
        cout << endl;
    }
    return 0;
}