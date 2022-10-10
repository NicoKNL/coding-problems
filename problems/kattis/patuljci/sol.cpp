#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> V(9);

    for (int i = 0; i < 9; ++i)
        cin >> V[i];

    for (int i = 0; i < 9; ++i)
        for (int ii = i + 1; ii < 9; ++ii)
            for (int iii = ii + 1; iii < 9; ++iii)
                for (int iv = iii + 1; iv < 9; ++iv)
                    for (int v = iv + 1; v < 9; ++v)
                        for (int vi = v + 1; vi < 9; ++vi)
                            for (int vii = vi + 1; vii < 9; ++vii)
                                if (V[i] + V[ii] + V[iii] + V[iv] + V[v] + V[vi] + V[vii] == 100)
                                {
                                    cout << V[i] << endl;
                                    cout << V[ii] << endl;
                                    cout << V[iii] << endl;
                                    cout << V[iv] << endl;
                                    cout << V[v] << endl;
                                    cout << V[vi] << endl;
                                    cout << V[vii] << endl;
                                }

    return 0;
}