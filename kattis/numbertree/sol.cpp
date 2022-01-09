#include <bits/stdc++.h>

using namespace std;

int main()
{
    int height;
    string path;

    cin >> height;
    if (!(cin >> path))
        path = "";

    int total = pow(2, height + 1) - 1;

    int index = 0;
    for (int i = 0; i < path.length(); ++i)
    {
        if (path[i] == 'L')
        {
            index *= 2;
        }
        else // 'R'
        {
            index *= 2;
            ++index;
        }
    }

    int nodes_above = pow(2, path.length()) - 1;

    cout << total - nodes_above - index << endl;

    return 0;
}