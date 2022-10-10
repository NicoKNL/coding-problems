#include <iostream>
#include <vector>

using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> divisors;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            divisors.push_back(i);
    }

    return divisors;
}

int main()
{
    int V;
    cin >> V;

    vector<int> divisors = get_divisors(V);

    int min_area = INT32_MAX;

    for (auto d1 : divisors)
        for (auto d2 : divisors)
            for (auto d3 : divisors)
                if (d1 * d2 * d3 == V)
                    min_area = min(min_area, 2 * d1 * d2 + 2 * d1 * d3 + 2 * d2 * d3);
    cout << min_area << endl;
    return 0;
}