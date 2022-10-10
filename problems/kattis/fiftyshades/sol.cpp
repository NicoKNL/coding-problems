#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    while (n--)
    {
        string s;
        cin >> s;

        for_each(s.begin(), s.end(), [](char &c)
                 { c = tolower(c); });

        if (s.find("pink") != string::npos || s.find("rose") != string::npos)
        {
            ++count;
        }
    }

    if (count)
    {
        cout << count << endl;
    }
    else
    {
        cout << "I must watch Star Wars with my daughter" << endl;
    }
    return 0;
}