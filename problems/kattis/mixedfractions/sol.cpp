#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int num, denum;
        cin >> num >> denum;

        if (num == 0 && denum == 0)
            break;

        int div = num / denum;
        num -= div * denum;

        cout << div << " " << num << " / " << denum << endl;
    }

    return 0;
}