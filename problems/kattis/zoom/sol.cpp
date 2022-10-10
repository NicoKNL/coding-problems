#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> V;
    for (int i = 1; i <= n; ++i)
    {
        long long tmp;
        cin >> tmp;
        if (i % k == 0)
            V.push_back(tmp);
    }

    for (int i = 0; i < V.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << V[i];
    }
    cout << endl;
}