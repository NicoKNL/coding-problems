#include <bits/stdc++.h>

using namespace std;

void PrintSolution(string & c, vector<vector<int>> & T, int i, int j) {
    if (i == 0) {
        return;
    } else {
        cout << "--" << c[i - 1] << endl;

        if (T[i-1][j] == T[i][j]) {
            PrintSolution(c, T, i-1, j);
        } else {
            PrintSolution(c, T, i-1, c[i-1] - 97);
            cout << c[i-1]; // C[i] for the solution, but this string is indexed 0 to n-1 instead of 1 to n
        }
    }
}

int main() {
    // Compute the solution
    string s = "aaybbddgdkdxxyz";
//    string s = "abcde";
//    string s = "zza";
//    string s = "xyza";
//    string s = "ayazbybzcyc";
    vector<vector<int>> T(s.size() + 1, vector<int>(26, 0));
    for (int i = 0; i < s.size() + 1; i++) { // for i = 1 to length of string
        for (int j = 0; j < 26; j++) { // for j = 'a' to 'z'
            if (i == 0) {
                T[i][j] = 0;
            } else { // i > 0
                int letter = s.at(i - 1) - 97; // Mapping 'a' -> 0, 'b' -> 1, ... , 'z' -> 25
                if (letter > j) {
                    T[i][j] = T[i-1][j];
                } else { // letter <= j
                    T[i][j] = max(T[i-1][j], 1 + T[i-1][letter]);
                }
            }
        }
    }
    cout << T[s.size()][25] << endl; // Length of optimal solution
    for (int i = 0; i < s.size() + 1; i++) {
        if (i == 0) {
            cout << "  ";
        } else {
            cout << s[i - 1] << " ";
        }
        for (int j = 0; j < 26; j++) {
            cout << T[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    // Extract the solution
    PrintSolution(s, T, s.size(), 25);
    cout << endl;
    return 0;
}