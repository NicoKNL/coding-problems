#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int expenses = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        if (tmp < 0)
            expenses += abs(tmp);
    }

    cout << expenses << endl;
    return 0;
}