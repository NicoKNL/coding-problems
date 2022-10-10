#include <bits/stdc++.h>

using namespace std;

string complementary(string s)
{
    string result;

    for (const auto &each : s)
    {
        if (each == 'A')
            result += 'T';
        if (each == 'T')
            result += 'A';
        if (each == 'C')
            result += 'G';
        if (each == 'G')
            result += 'C';
    }

    return result;
}

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    cout << complementary(S) << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}