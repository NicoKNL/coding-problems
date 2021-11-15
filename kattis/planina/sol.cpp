#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int width = 2;
    for (int i = 0; i < N; ++i)
    {
        width += (width - 1);
    }
    cout << (width * width) << endl;

    return 0;
}