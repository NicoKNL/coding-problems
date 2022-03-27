#include <bits/stdc++.h>

using namespace std;
vector<double> gauss(vector<vector<double>> A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(A[k][i]) > maxEl)
            {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }
        for (int k = i; k < n + 1; k++)
        {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        for (int k = i + 1; k < n; k++)
        {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < n + 1; j++)
            {
                if (i == j)
                {
                    A[k][j] = 0;
                }
                else
                {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = A[i][n] / A[i][i];
        for (int k = i - 1; k >= 0; k--)
        {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main()
{
    int n, b;

    cin >> n >> b;
    cout << n << " " << b << endl;
    vector<vector<double>> V;
    for (int i = 0; i < n; ++i)
    {
        double cost, health, potency;
        cin >> cost >> health >> potency;
        V.push_back({cost, health, potency});
    }
    cout << "here" << endl;

    vector<double> result = gauss(V);
    cout << "gaus" << endl;
    for (auto each : result)
    {
        cout << each << " ";
    }
    cout << endl;
    return 0;
}