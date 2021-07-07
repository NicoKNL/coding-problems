#include <bits/stdc++.h>

using namespace std;

unordered_set<long long> cache;
int best;

void recurse(unsigned long long & s, unsigned long long & e, int current)
{
    if (s == e)
    {
        if (best == -1 || current < best)
        {
            best = current;
        }
        return;
    }

    if (current >= 5) return;

    s = s << 1;
    cout << "A recursing!: " << s << endl;
    recurse(s, e, current + 1);
    s = s >> 1;
    s = ~s;
    cout << "B recursing!: " << s << endl;
    recurse(s, e, current + 1);
    s = ~s;
}


int solve()
{
    cache = unordered_set<long long>();
    best = -1;

    string S, E;

    cin >> S >> E;

    unsigned long long s = stoi(S, 0, 2);
    unsigned long long e = stoi(E, 0, 2);

    cout << "S: " << s << endl;
    cout << "E: " << e << endl;

    recurse(s, e, 0);
    return best;
}

int main()
{
    int T;
    int c = 1;

    cin >> T;

    while (T--)
    {
        int result = solve();
        
        if (result == -1)
        {
            cout << "Case #" << c << ": IMPOSSIBLE\n";
        }
        else
        {
            cout << "Case #" << c << ": " << result << "\n";
        }

        c++;
    }
}