#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g, s, c;
    cin >> g >> s >> c;

    int buying_power = 3 * g + 2 * s + 1 * c;

    string result;

    if (buying_power >= 6)
    {
        result = "Gold";
    }
    else if (buying_power >= 3)
    {
        result = "Silver";
    }
    else
    {
        result = "Copper";
    }

    if (buying_power >= 8)
    {
        result = "Province or " + result;
    }
    else if (buying_power >= 5)
    {
        result = "Duchy or " + result;
    }
    else if (buying_power >= 2)
    {
        result = "Estate or " + result;
    }

    cout << result << endl;

    return 0;
}