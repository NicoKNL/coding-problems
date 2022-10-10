#include <bits/stdc++.h>

using namespace std;

pair<int, int> calculateCorrectProblems(int n)
{
    int correct = n / 100;

    return {correct, n - correct * 100};
}

void solve()
{
    int N;
    cin >> N;

    auto [answers100, answers1] = calculateCorrectProblems(N);
    if (answers100 + answers1 > 10)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answers100 + answers1 << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}