#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    bool first = true;
    while(getline(cin, s))
    {
        for (char& c: s)
        {
            if (c == '\"') {
                if (first) {
                    cout << "``";
                    first = false;
                } else {
                    cout << "''";
                    first = true;
                }
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}