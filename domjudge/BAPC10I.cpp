#include <iostream>
#include <string>
#include <list>

using namespace std;

void oneRun()
{
    string input;
    cin >> input;

    list<char> r = {};
    list<char>::iterator r_it = r.begin();
    char token;

    for (string::iterator it = input.begin(); it != input.end(); ++it) {
        token = *it;
        if (token == '<') r_it != r.begin() ? --r_it : r.begin();
        else if (token == '>') r_it != r.end() ? ++r_it : r.end();
        else if (token == '-') r_it != r.begin() ? r_it = r.erase(--r_it) : r_it = r_it;
        else r_it = ++r.insert(r_it, 1, token);
    }

    for (list<char>::iterator i = r.begin(); i != r.end(); ++i) {
        cout << *i;
    }
    cout << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}