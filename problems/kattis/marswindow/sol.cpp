#include <bits/stdc++.h>

using namespace std;

vector<int> relativeMonthsInYear(int year)
{
    vector<int> months;

    int start_month = (year - 2018) * 12;

    for (int i = 0; i < 12; ++i)
        months.push_back(start_month + i);

    return months;
}

int main()
{
    int n;
    cin >> n;

    vector<int> months_of_year = relativeMonthsInYear(n);

    bool window = false;
    for (auto each : months_of_year)
        if ((each - 3) % 26 == 0)
        {
            window = true;
            break;
        }

    if (window)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}