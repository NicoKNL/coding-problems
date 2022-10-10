#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

T sum(T n)
{
    T result = 0;
    for (int i = 1; i <= n; ++i)
        result += i;
    return result;
}

T odd(T n)
{
    T result = 0;
    int i = 1;
    int count = 0;
    while (count < n)
    {
        if ((i & 1) == 1)
        {
            result += i;
            ++count;
        }
        ++i;
    }
    return result;
}

T even(T n)
{
    T result = 0;
    int i = 1;
    int count = 0;
    while (count < n)
    {
        if ((i & 1) == 0)
        {
            result += i;
            ++count;
        }
        ++i;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, m;
        cin >> k >> m;

        printf("%d %llu %llu %llu\n", k, sum(m), odd(m), even(m));
    }
    return 0;
}