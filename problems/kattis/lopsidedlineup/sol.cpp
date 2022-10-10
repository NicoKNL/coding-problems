#include <bits/stdc++.h>

typedef long long T;
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<T> strength;

    for (int r = 0; r < N; ++r)
    {
        T s = 0;
        for (int c = 0; c < N; ++c)
        {
            T tmp;
            cin >> tmp;
            s += tmp;
        }

        strength.push_back(s);
    }

    sort(strength.begin(), strength.end());

    T weak = accumulate(strength.begin(), strength.begin() + N / 2, 0ll);
    T strong = accumulate(strength.begin() + N / 2, strength.end(), 0ll);

    cout << (strong - weak) / 2 << endl;

    return 0;
}