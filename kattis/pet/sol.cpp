#include <bits/stdc++.h>

using namespace std;

int main()
{
    int max_sum = 0;
    int winner = 0;

    for (int i = 0; i < 5; ++i)
    {
        int sum = 0;
        for (int ii = 0; ii < 4; ++ii)
        {
            int tmp;
            cin >> tmp;

            sum += tmp;
        }

        if (sum > max_sum)
        {
            max_sum = sum;
            winner = i + 1;
        }
    }

    cout << winner << " " << max_sum << endl;
    return 0;
}