#include <bits/stdc++.h>

using namespace std;

int main() {
    const unsigned int setsize = 10;

    for (unsigned long long bits = 0x00;
         bits < 0x01 << setsize; bits+=0x01) {
        bitset<setsize> mybits(bits);
        cout << mybits << endl;
    }
    return 0;
}