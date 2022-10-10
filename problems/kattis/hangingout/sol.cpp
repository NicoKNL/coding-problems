#include <bits/stdc++.h>

using namespace std;

int main()
{
    int limit, n;
    cin >> limit >> n;

    int current = 0;
    int denied = 0;

    for (int i = 0; i < n; ++i)
    {
        string s;
        int people;

        cin >> s >> people;

        if (s == "leave")
            current -= people;
        else
        {
            if (people + current > limit)
                ++denied;
            else
                current += people;
        }
    }

    cout << denied << endl;
    return 0;
}