#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss;
        ss.str(line);

        vector<unsigned long long> V{0, 0};
        ss >> V[0] >> V[1];

        sort(V.begin(), V.end());

        cout << (V[1] - V[0]) << endl;
    }

    return 0;
}