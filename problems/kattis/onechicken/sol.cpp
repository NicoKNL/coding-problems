#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    if (N < M)
    {
        if ((M - N) > 1)
            printf("Dr. Chaz will have %d pieces of chicken left over!\n", M - N);
        else
            printf("Dr. Chaz will have 1 piece of chicken left over!\n");
    }
    else
    {
        if ((N - M) > 1)
            printf("Dr. Chaz needs %d more pieces of chicken!\n", N - M);
        else
            printf("Dr. Chaz needs 1 more piece of chicken!\n");
    }

    return 0;
}