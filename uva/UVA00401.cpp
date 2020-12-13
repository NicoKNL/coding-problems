#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<char, char> umap;
    umap['A'] = 'A'; umap['B'] = '0'; umap['C'] = '0'; umap['D'] = '0';
    umap['E'] = '3'; umap['F'] = '0'; umap['G'] = '0'; umap['H'] = 'H';
    umap['I'] = 'I'; umap['J'] = 'L'; umap['K'] = '0'; umap['L'] = 'J';
    umap['M'] = 'M'; umap['N'] = '0'; umap['O'] = 'O'; umap['P'] = '0';
    umap['Q'] = '0'; umap['R'] = '0'; umap['S'] = '2'; umap['T'] = 'T';
    umap['U'] = 'U'; umap['V'] = 'V'; umap['W'] = 'W'; umap['X'] = 'X';
    umap['Y'] = 'Y'; umap['Z'] = '5'; umap['1'] = '1'; umap['2'] = 'S';
    umap['3'] = 'E'; umap['4'] = '0'; umap['5'] = 'Z'; umap['6'] = '0';
    umap['7'] = '0'; umap['8'] = '8'; umap['9'] = '0';

    bool palindrome, mirrored;
    string s;
    while (getline(cin, s)) {
        palindrome = true;
        mirrored = true;
        int i = 0, j = s.size() - 1;
        char a, b;
        while (i <= j) {
            a = s.at(i);
            b = s.at(j);

            if (umap[a] != b) {
                mirrored = false;
            }

            if (a != b) {
                palindrome = false;
            }
            i++;
            j--;
        }

        if (palindrome && mirrored) {
            cout << s << " -- is a mirrored palindrome." << endl;
        } else if (palindrome && !mirrored) {
            cout << s << " -- is a regular palindrome." << endl;
        } else if (!palindrome && mirrored) {
            cout << s << " -- is a mirrored string." << endl;
        } else {
            cout << s << " -- is not a palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}