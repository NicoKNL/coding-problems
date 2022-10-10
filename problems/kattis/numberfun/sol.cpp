#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<char> V{'+', '-', '*', '/'};
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        bool possible = false;
        for (const auto &op : V)
        {
            if (op == '+')
            {
                if (a + b == c)
                    possible = true;
            }
            else if (op == '-')
            {
                if (a - b == c || b - a == c)
                    possible = true;
            }
            else if (op == '*')
            {
                if (a * b == c)
                    possible = true;
            }
            else if ((double)a / (double)b == (double)c || (double)b / (double)a == (double)c)
                possible = true;
        }

        if (possible)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}