#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> difference(const vector<int> &V, const vector<int> &ref, int xor_0, int xor_1)
{
    vector<pair<int, int>> moves;

    for (int i = 0; i < V.size(); ++i)
        if (V[i] != ref[i])
        {
            if (ref[i] == 0)
                moves.push_back({i, xor_0});
            else
                moves.push_back({i, xor_1});
        }

    return moves;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> V(n);
        vector<int> zero_first(n);
        vector<int> one_first(n);

        bool zero = false;
        bool one = false;

        int zero_i = -1;
        int one_i = -1;

        for (int i = 0; i < n; ++i)
        {
            unsigned long long tmp;
            cin >> tmp;
            V[i] = tmp & 1;

            if (V[i] == 0)
            {
                zero = true;
                zero_i = i;
            }

            if (V[i] == 1)
            {
                one = true;
                one_i = i;
            }

            if (i % 2 == 0)
            {
                zero_first[i] = 0;
                one_first[i] = 1;
            }
            else
            {
                zero_first[i] = 1;
                one_first[i] = 0;
            }
        }

        vector<pair<int, int>> diff0 = difference(V, zero_first, zero_i, one_i);
        vector<pair<int, int>> diff1 = difference(V, one_first, zero_i, one_i);

        if (zero && one)
        {
            if (diff0.size() < diff1.size())
            {
                cout << "010" << endl;
                cout << diff0.size() << endl;
                for (auto [a, b] : diff0)
                    cout << a + 1 << " " << b + 1 << endl;
            }
            else
            {
                cout << "101" << endl;
                cout << diff1.size() << endl;
                for (auto [a, b] : diff1)
                    cout << a + 1 << " " << b + 1 << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}