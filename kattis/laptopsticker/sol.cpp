#include <bits/stdc++.h>

using namespace std;

int main()
{
    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    bool it_fits = ws <= (wc - 2) && hs <= (hc - 2);
    cout << it_fits << endl;

    return 0;
}