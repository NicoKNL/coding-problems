#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool first = true;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        if (!first)
            cout << endl;

        first = false;

        vector<int> A(n, 0);
        vector<int> B(n, 0);

        for (int i = 0; i < n; ++i)
            cin >> A[i];

        for (int i = 0; i < n; ++i)
            cin >> B[i];

        vector<int> ref(A);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        map<int, int> M;

        for (int i = 0; i < n; ++i)
        {
            M[A[i]] = B[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cout << M[ref[i]] << endl;
        }
    }

    return 0;
}