#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        /* Enter your code here */
        cout << hex;
        cout << showbase;
        cout << left;
        cout << nouppercase;
        cout << (long) A << endl;

        cout << dec;
        cout << right;
        cout << setfill('_') << setw(15);
        cout << fixed << setprecision(2) << showpos;
        cout << B << endl;

        cout << scientific;
        cout << noshowpos;
        cout << setprecision(9);
        cout << uppercase;
        cout << C << endl;
    }
    return 0;

}