#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> P(14, false);
    vector<bool> K(14, false);
    vector<bool> H(14, false);
    vector<bool> T(14, false);

    char s;
    int n;
    while (cin >> s >> n)
    {
        if (s == 'P')
        {
            if (P[n])
            {
                cout << "GRESKA" << endl;
                return 0;
            }
            else
            {
                P[n] = true;
            }
        }
        else if (s == 'K')
        {
            if (K[n])
            {
                cout << "GRESKA" << endl;
                return 0;
            }
            else
            {
                K[n] = true;
            }
        }
        else if (s == 'H')
        {
            if (H[n])
            {
                cout << "GRESKA" << endl;
                return 0;
            }
            else
            {
                H[n] = true;
            }
        }
        else
        { // s == 'T'
            if (T[n])
            {
                cout << "GRESKA" << endl;
                return 0;
            }
            else
            {
                T[n] = true;
            }
        }
    }

    int sum_P = 13 - accumulate(P.begin(), P.end(), 0);
    int sum_K = 13 - accumulate(K.begin(), K.end(), 0);
    int sum_H = 13 - accumulate(H.begin(), H.end(), 0);
    int sum_T = 13 - accumulate(T.begin(), T.end(), 0);

    printf("%d %d %d %d\n", sum_P, sum_K, sum_H, sum_T);

    return 0;
}