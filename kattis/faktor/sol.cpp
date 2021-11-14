#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A_articles, I_impact;

    cin >> A_articles >> I_impact;

    --I_impact;

    int bribes = I_impact * A_articles;
    bribes += 1;
    cout << bribes << endl;

    return 0;
}