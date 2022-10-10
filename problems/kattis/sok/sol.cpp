#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    double A, B, C, I, J, K;
    cin >> A >> B >> C >> I >> J >> K;

    double r1 = A / I;
    double r2 = B / J;
    double r3 = C / K;

    double minr = min(r1, min(r2, r3));

    A -= minr * I;
    B -= minr * J;
    C -= minr * K;

    cout << A << " " << B << " " << C << endl;

    return 0;
}