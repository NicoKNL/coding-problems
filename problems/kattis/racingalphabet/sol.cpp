#include <bits/stdc++.h>

using namespace std;

double distInTime(int steps)
{
    double perim = 2 * M_PI * 30.0;
    double perim_per_step = perim / 28.0;
    double feet_per_second = 15.0;

    return perim_per_step * steps / feet_per_second;
}

int main()
{
    fixed(cout);
    cout.precision(10);

    unordered_map<char, int> M;
    int i = 0;
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        M[c] = i;
        ++i;
    }

    M[' '] = i;
    ++i;
    M['\''] = i;

    string line;
    getline(cin, line);
    stringstream ss;
    ss << line;

    int n;
    ss >> n;

    while (n--)
    {
        double result = 0.0;
        string s;
        getline(cin, s);
        char prev_c = s[0];
        for (int ci = 1; ci < s.length(); ++ci)
        {
            char c = s[ci];
            int dist = abs(M[c] - M[prev_c]);
            int opt_dist = min(dist, 28 - dist);

            result += distInTime(opt_dist);

            prev_c = c;
        }

        result += s.length();

        cout << result << endl;
    }

    return 0;
}