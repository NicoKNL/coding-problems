#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    vector<int> counter(10, 0);
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        stringstream ss;
        ss << s;

        string signal;
        for (int i = 0; i < 10; ++i)
            ss >> signal;

        char delim;
        ss >> delim;

        for (int i = 0; i < 4; ++i)
        {
            ss >> signal;
            set<char> S(signal.begin(), signal.end());

            if (S.size() == 2)
                ++counter[1];
            else if (S.size() == 3)
                ++counter[7];
            else if (S.size() == 4)
                ++counter[4];
            else if (S.size() == 7)
                ++counter[8];
        }
    }
    cout << accumulate(counter.begin(), counter.end(), 0) << endl;

    return 0;
}