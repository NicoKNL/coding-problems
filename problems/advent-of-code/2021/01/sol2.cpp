#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    vector<int> V;
    while (getline(cin, s))
    {
        stringstream ss;
        ss.str(s);

        int n;
        ss >> n;

        V.push_back(n);
    }

    int count = 0;
    int prev_sum = -1;

    for (int i = 0; i < V.size() - 2; ++i)
    {
        int sum = V[i] + V[i + 1] + V[i + 2];

        if (sum > prev_sum && prev_sum != -1)
        {
            ++count;
        }
        prev_sum = sum;
    }

    cout << count << endl;

    return 0;
}