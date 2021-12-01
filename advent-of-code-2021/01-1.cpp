#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int prev_n = -1;
    int count = 0;

    while (getline(cin, s))
    {
        stringstream ss;
        ss.str(s);

        int n;
        ss >> n;

        if (n > prev_n && prev_n != -1)
            ++count;

        prev_n = n;
    }

    cout << count << endl;

    return 0;
}