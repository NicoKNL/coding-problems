#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int imp = 0;

        int prev_digit;
        int digit;

        cin >> digit;
        prev_digit = digit;

        while (true)
        {
            cin >> digit;
            if (digit == 0)
                break;

            if (2 * prev_digit < digit)
            {
                imp += digit - prev_digit * 2;
            }
            prev_digit = digit;
        }

        cout << imp << endl;
    }

    return 0;
}