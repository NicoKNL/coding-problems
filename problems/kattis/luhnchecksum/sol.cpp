#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        vector<int> V(s.length(), -1);

        for (int i = s.length() - 2; i >= 0; i -= 2)
        {
            int tmp = s[i] - '0';
            tmp *= 2;

            if (tmp > 9)
                V[i] = (tmp / 10) + (tmp % 10);
            else
                V[i] = tmp;
        }

        for (int i = 0; i < s.length(); ++i)
            if (V[i] == -1)
                V[i] = s[i] - '0';

        int sum = accumulate(V.begin(), V.end(), 0);

        if (sum % 10 == 0)
            cout << "PASS" << endl;
        else
            cout << "FAIL" << endl;
    }

    return 0;
}