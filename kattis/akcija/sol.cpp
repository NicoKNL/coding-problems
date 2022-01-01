#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end(), [](int a, int b)
         { return a > b; });

    int free_books = n / 3;

    for (int i = 0; i < n && free_books; ++i)
    {
        if (i % 3 == 2)
        {
            V[i] = 0;
            --free_books;
        }
    }

    int result = accumulate(V.begin(), V.end(), 0);

    cout << result << endl;

    return 0;
}