#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

map<char, char> mm =
        {
                {'A', '2'},
                {'B', '2'},
                {'C', '2'},

                {'D', '3'},
                {'E', '3'},
                {'F', '3'},

                {'G', '4'},
                {'H', '4'},
                {'I', '4'},

                {'J', '5'},
                {'K', '5'},
                {'L', '5'},

                {'M', '6'},
                {'N', '6'},
                {'O', '6'},

                {'P', '7'},
                {'R', '7'},
                {'S', '7'},

                {'T', '8'},
                {'U', '8'},
                {'V', '8'},

                {'W', '9'},
                {'X', '9'},
                {'Y', '9'},

        };

string cleanup(string s) {
    string result;
    for (char c : s) {
        if (c == '-') continue;

        if (mm.find(c) != mm.end()) {
            result += mm[c];
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int cases = 1;
    while (N--) {
        if (cases > 1) cout << endl;
        int p;
        cin >> p;
        vector<string> numbers(p);
        map<string, int> m;
        loop(i, p) {
            cin >> numbers[i];
            numbers[i] = cleanup(numbers[i]);
            m[numbers[i]]++;
        }

        bool found = false;
        for (auto entry : m) {
            if (entry.second < 2) continue;
            found = true;
            string s = entry.first;
            string a = s.substr(0, 3);
            string b = s.substr(3);
            printf("%s-%s %d\n", a.c_str(), b.c_str(), entry.second);
        }

        if (!found) printf("No duplicates.\n");
        cases++;

    }
    return 0;
}

/*
1

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

 */