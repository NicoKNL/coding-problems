#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int ng, nm;
        cin >> ng >> nm;

        vector<long long> GZ(ng);
        vector<long long> MGZ(nm);

        for (int i = 0; i < ng; ++i)
            cin >> GZ[i];

        for (int i = 0; i < nm; ++i)
            cin >> MGZ[i];

        sort(GZ.begin(), GZ.end());
        sort(MGZ.begin(), MGZ.end());

        int g_i = 0;
        int m_i = 0;

        while (g_i < ng && m_i < nm)
        {
            if (GZ[g_i] >= MGZ[m_i])
                ++m_i;
            else
                ++g_i;
        }

        if (g_i != ng)
            cout << "Godzilla" << endl;
        else if (m_i != nm)
            cout << "MechaGodzilla" << endl;
        else
            cout << "uncertain" << endl;
    }

    return 0;
}