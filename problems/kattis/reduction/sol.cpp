#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int computeOptimalCost(double START, double END, int A, int B)
{
    priority_queue<pair<int, double>> PQ; // {cost, CURRENT_WORK}

    // Cost of reducing 1 unit straight up
    double cost1A = (double)A;
    double cost1B = ((double)B) / (END - CURRENT_WORK);

    return 42;
}

void solve(int casenum)
{
    cout << "Case " << casenum << endl;
    double START, END;
    int agencies;
    cin >> START >> END >> agencies;
    cout << START << " " << END << " " << agencies << endl;

    vector<pair<int, string>> V;

    for (int i = 0; i < agencies; ++i)
    {
        string s;
        cin >> s;

        int colon = s.find(':');
        string agency = s.substr(0, colon);
        string data = s.substr(colon + 1);

        int A, B;
        sscanf(data.c_str(), "%d,%d", &A, &B);
        cout << agency << endl;
        cout << data << endl;
        cout << A << " - " << B << endl;

        V.push_back({computeOptimalCost(START, END, A, B), agency});
    }

    sort(V.begin(), V.end());
    cout << V[0].first << V[0].second << endl;
}

int main()
{
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; ++i)
        solve(i);
}