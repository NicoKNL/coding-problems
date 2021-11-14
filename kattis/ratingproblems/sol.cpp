#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n_judges, k_judges_done;
    cin >> n_judges >> k_judges_done;

    double score = 0;
    for (int i = 0; i < k_judges_done; ++i)
    {
        double tmp;
        cin >> tmp;
        score += tmp;
    }

    double min_score = score + (n_judges - k_judges_done) * -3;
    min_score /= n_judges;

    double max_score = score + (n_judges - k_judges_done) * 3;
    max_score /= n_judges;

    cout << min_score << " " << max_score << endl;

    return 0;
}