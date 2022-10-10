#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string a, b;
    cin >> a >> b;
    string ab, amix, bmix;
    int alen, blen;
    alen = a.size();
    blen = b.size();
    ab = a + b;
    amix = a;
    amix[0] = b[0];
    bmix = b;
    bmix[0] = a[0];
    printf("%d %d\n", alen, blen);
    printf("%s\n", ab.c_str());
    printf("%s %s\n", amix.c_str(), bmix.c_str());
    return 0;
}

