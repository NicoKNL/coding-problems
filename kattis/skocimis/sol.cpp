#include <bits/stdc++.h>

using namespace std;

int dist(int a, int b)
{
    return b - a;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    while (dist(a, b) > 1 || dist(b, c) > 1)
    {
        int left = dist(a, b);
        int right = dist(b, c);

        if (left < right)
        {
            a = c - 1;
            swap(a, b);
        }
        else
        {
            c = a + 1;
            swap(b, c);
        }
        ++count;
    }

    cout << count << endl;

    return 0;
}