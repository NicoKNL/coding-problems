#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

#define MOD 1000000007

map<T, T> mapA;
map<T, T> mapB;
map<T, T> mapC;

T n, a, b, c;

T recurseA(T n);
T recurseB(T n);
T recurseC(T n);

T recurseA(T n)
{
    if (n == 0)
        return 1;

    if (mapA.find(n) != mapA.end())
    {
        return mapA[n];
    }

    T result = (b * recurseB(n - 1) + c * recurseC(n - 1)) % MOD;
    mapA[n] = result;
    return result;
}

T recurseB(T n)
{
    if (n == 0)
        return 1;
    if (mapB.find(n) != mapB.end())
    {
        return mapB[n];
    }

    T result = (a * recurseA(n - 1) + c * recurseC(n - 1)) % MOD;
    mapB[n] = result;
    return result;
}

T recurseC(T n)
{
    if (n == 0)
        return 1;

    if (mapC.find(n) != mapC.end())
    {
        return mapC[n];
    }

    T result = (a * recurseA(n - 1) + b * recurseB(n - 1)) % MOD;
    mapC[n] = result;
    return result;
}

int main()
{
    cin >> n >> a >> b >> c;

    T result = 0;
    result += a * recurseA(n - 1);
    result %= MOD;
    result += b * recurseB(n - 1);
    result %= MOD;
    result += c * recurseC(n - 1);
    result %= MOD;

    cout << result << endl;

    return 0;
}