#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int target;
        cin >> target;

        int div = target / 400;
        if (target - div * 400)
            cout << div + 1 << endl;
        else
            cout << div << endl;
    }

    return 0;
}