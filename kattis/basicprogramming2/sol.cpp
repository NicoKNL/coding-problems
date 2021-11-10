#include <bits/stdc++.h>

using namespace std;

void solve1(int N)
{
    unordered_map<int, int> M;

    while (N--)
    {
        int tmp;
        cin >> tmp;
        ++M[tmp];
    }

    for (auto &each : M)
    {
        int other = 7777 - each.first;

        if (M.find(other) != M.end())
        {
            if (each.first != other)
            {
                cout << "Yes" << endl;
                exit(0);
            }
            else if (each.first == other && M[other] >= 2)
            {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }

    cout << "No" << endl;
    exit(0);
}

void solve2(int N)
{
    unordered_map<int, int> M;

    while (N--)
    {
        int tmp;
        cin >> tmp;
        ++M[tmp];

        if (M[tmp] > 1)
        {
            cout << "Contains duplicate" << endl;
            exit(0);
        }
    }

    cout << "Unique" << endl;
    exit(0);
}

void solve3(int N)
{
    unordered_map<int, int> M;

    int half = N / 2;

    while (N--)
    {
        int tmp;
        cin >> tmp;
        ++M[tmp];

        if (M[tmp] > half)
        {
            cout << tmp << endl;
            exit(0);
        }
    }

    cout << -1 << endl;
    exit(0);
}

void solve4(int N)
{
    vector<int> V;

    while (N--)
    {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }

    sort(V.begin(), V.end());

    if (V.size() & 1)
    {
        cout << V[V.size() / 2] << endl;
    }
    else
    {
        cout << V[V.size() / 2 - 1] << " " << V[V.size() / 2] << endl;
    }
    exit(0);
}

void solve5(int N)
{
    vector<int> V;

    while (N--)
    {
        int tmp;
        cin >> tmp;
        if (100 <= tmp && tmp <= 999)
        {

            V.push_back(tmp);
        }
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << V[i];
    }
    cout << endl;
    exit(0);
}

int main()
{
    int N, t;
    cin >> N >> t;

    switch (t)
    {
    case 1:
        solve1(N);
        break;
    case 2:
        solve2(N);
        break;
    case 3:
        solve3(N);
        break;
    case 4:
        solve4(N);
        break;
    case 5:
        solve5(N);
        break;
    }
    return 0;
}