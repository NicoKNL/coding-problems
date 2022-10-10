#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    int T = 1;
    while (cin >> a >> b >> c >> d)
    {
        vector<vector<int>> M = {{a, b}, {c, d}};

        int det = a * d - b * c;

        vector<vector<int>> M_inv = {{det * d, det * -b},
                                     {det * -c, det * a}};

        cout << "Case " << T << ":\n";
        cout << M_inv[0][0] << " " << M_inv[0][1] << "\n";
        cout << M_inv[1][0] << " " << M_inv[1][1] << "\n";
        ++T;
    }
}