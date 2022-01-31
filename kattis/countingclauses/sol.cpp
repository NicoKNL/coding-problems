#include <bits/stdc++.h>

using namespace std;

int main()
{
    int clauses, literals;
    cin >> clauses >> literals;

    if (clauses < 8)
    {
        cout << "unsatisfactory" << endl;
    }
    else
    {
        cout << "satisfactory" << endl;
    }

    return 0;
}