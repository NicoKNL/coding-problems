#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i = 1;

    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        stringstream ss;
        ss << line;

        int n;
        ss >> n;

        vector<int> V(n, 0);
        for (int i = 0; i < n; ++i)
            ss >> V[i];

        int MIN = *min_element(V.begin(), V.end());
        int MAX = *max_element(V.begin(), V.end());
        int RANGE = MAX - MIN;

        cout << "Case " << i << ": " << MIN << " " << MAX << " " << RANGE << endl;
        ++i;
    }

    return 0;
}