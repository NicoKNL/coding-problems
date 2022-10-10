#include <bits/stdc++.h>

using namespace std;

bool isValidSubstring(map<int, int> &M, map<int, int> &C)
{
    // map<int, int> C;

    // for (int i = start; i <= end; ++i)
    // {
    //     ++C[V[i]];
    // }

    // cout << " C MAP " << endl;
    // for (auto &c : C)
    // {
    //     cout << "C: " << c.first << " :: " << c.second << endl;
    // }
    // cout << "  END  " << endl;
    for (auto &m : M)
    {
        if (C[m.first] < m.second)
            return false;
    }

    return true;
}

int main()
{
    int N, K, R;
    cin >> N >> K >> R;

    vector<int> V(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
    }

    int count = 0;
    int sum = 0;
    map<int, int> M;
    for (int i = 0; i < R; ++i)
    {
        int B, Q;
        cin >> B >> Q;
        // cout << "BQ: " << B << " , " << Q << endl;
        M[B] = Q;
        count += Q;
        sum += B * Q;
    }

    // cout << "SUM: " << sum << endl;
    set<int> guesses;
    int min = count;
    int max = N;

    int digits = min + (max - min) / 2;

    // cout << "digits: " << digits << endl;
    bool found = false;
    int opt = -1;

    // while (digits <= N)
    while (guesses.find(digits) == guesses.end())
    {
        // cout << "-------------------------" << endl;
        map<int, int> C;
        found = false;
        guesses.insert(digits);
        int s = 0;
        for (int i = 0; i < N && i < N; ++i)
        {
            ++C[V[i]];
            s += V[i];
            if (i >= digits)
            {
                s -= V[i - digits];
                --C[V[i - digits]];
            }
            // cout << "s: " << s << endl;

            if (i >= digits - 1 && s >= sum)
            {
                // cout << " checking " << endl;
                if (isValidSubstring(M, C))
                {
                    // cout << "found" << digits << endl;
                    if (opt == -1 || digits < opt)
                    {
                        opt = digits;
                    }
                    found = true;
                    // return 0;
                }
            }
        }

        if (found)
        {
            max = digits;
        }
        else
        {
            min = digits;
        }

        digits = min + (max - min) / 2;
        // cout << "min: " << min << " :: "
        //      << "max: " << max << endl;
        // cout << "digits: " << digits << endl;
        // ++digits;
    }
    if (opt > -1)
    {
        cout << opt << endl;
    }
    else
    {

        cout << "impossible" << endl;
    }
    return 0;
}