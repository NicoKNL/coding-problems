#include <bits/stdc++.h>

using namespace std;

int main()
{
    int width, n;
    cin >> width >> n;

    vector<int> V = {0};
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }

    V.push_back(width);

    vector<bool> possible(width + 1, false);

    for (int a : V)
        for (int b : V)
            possible[abs(a - b)] = true;

    for (int i = 1; i < possible.size(); ++i)
    {
        if (possible[i])
        {
            if (i > 1)
                cout << " ";

            cout << i;
        }
    }

    cout << endl;

    return 0;
}