#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double w, h;
    cin >> n >> w >> h;

    double limit = sqrt(w * w + h * h);

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp <= limit)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
    }
    return 0;
}