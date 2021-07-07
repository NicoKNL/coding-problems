#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    string line;
    regex reg("[a-zA-Z]+");
    while (getline(cin, line)) {
        auto words_begin = sregex_iterator(line.begin(), line.end(), reg);
        auto words_end = sregex_iterator();

        // word count
        cout << distance(words_begin, words_end) << endl;

        // output words
//        for (auto i = words_begin; i != words_end; i++) {
//            smatch match = *i;
//            string match_str = match.str();
//            cout << match_str << endl;
//        }
    }
    return 0;
}