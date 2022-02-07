#include <bits/stdc++.h>

using namespace std;

int distToPalindrome(string s)
{
    int dist = 0;

    for (int i = 0; i < s.length() / 2; ++i)
        if (s[i] != s[s.length() - i - 1])
            ++dist;

    return dist;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int dist = distToPalindrome(s);

        if (dist > k)
            cout << "NO" << endl;
        else if (dist == k)
            cout << "YES" << endl;
        else // if (dist < k)
            if (n % 2 == 0 && (k - dist) % 2 == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}