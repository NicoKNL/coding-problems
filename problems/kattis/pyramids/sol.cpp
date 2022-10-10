#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    unsigned long long needed_for_height = 1;
    int height = 1;
    while (n > needed_for_height)
    {
        ++height;
        needed_for_height += ((2 * height - 1) * (2 * height - 1));
    }

    if (n == needed_for_height)
    {

        cout << height << endl;
    }
    else
    {
        cout << height - 1 << endl;
    }
    return 0;
}