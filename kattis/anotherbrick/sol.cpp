#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> bricks(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> bricks[i];
        sum += bricks[i];
    }

    if (sum < h * w)
    {
        cout << "NO" << endl;
        return 0;
    }

    int W_ = w;
    int H_ = 0;
    for (int i = 0; i < n; ++i)
    {
        if (bricks[i] <= W_)
            W_ -= bricks[i];
        else
        {
            cout << "NO" << endl;
            return 0;
        }

        if (W_ == 0)
        {
            W_ = w;
            ++H_;
        }

        if (H_ == h)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}