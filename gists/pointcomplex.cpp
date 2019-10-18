#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()

// example
int main() {
    pt a{2, 3};
    pt b{5, 2};
    cout << a.x << " " << a.y << endl;
    cout << b << endl;

//    a.x = 1; // does not compile
    a = {1, 2}; // correct
    return 0;
}