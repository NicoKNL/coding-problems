#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        vector<string> S;

        string line;
        getline(cin, line);

        stringstream ss;
        ss << line;

        string s;
        while (ss >> s)
            S.push_back(s);

        while (getline(cin, line))
        {
            if (line.length() == 0)
                break;
            else if (line == "what does the fox say?")
            {
                int i = 0;
                for (auto each : S)
                {
                    if (i > 0)
                        cout << " ";
                    cout << each;
                    ++i;
                }
                cout << endl;
                break;
            }
            else
            {
                stringstream tt;
                tt << line;
                string tmp;
                tt >> tmp >> tmp >> tmp;

                auto it = find(S.begin(), S.end(), tmp);
                while (it != S.end())
                {
                    S.erase(it);
                    it = find(S.begin(), S.end(), tmp);
                }
            }
        }
    }

    return 0;
}