#include <iostream>

using namespace std;

void run()
{
    int n, m, n_divs, m_divs;
    cin >> n >> m;

    n -= 2;
    m -= 2;

    n_divs = n/3;
    m_divs = m/3;

    if (n % 3 > 0) n_divs++;
    if (m % 3 > 0) m_divs++;

    cout << n_divs * m_divs << endl;
}

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        run();
    }
    return 0;
}