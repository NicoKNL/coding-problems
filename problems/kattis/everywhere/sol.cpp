#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        int P;
        cin >> P;
        set<string> places;

        while (P--)
        {
            string tmp;
            cin >> tmp;
            places.insert(tmp);
        }

        cout << places.size() << endl;
    }

    return 0;
}
