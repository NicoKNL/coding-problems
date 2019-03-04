#include <iostream>

using namespace std;

long reverse(long a) {
    long ra = a;
    long i = 1;
    while (ra > 0) {
        ra /= 10;
        i *= 10;
    }

    i /= 10;
    ra = 0;
    while (a > 0) {
        ra += (a % 10) * i;
        a /= 10;
        i /= 10;
    }
    return ra;
}

void runOnce() {
    long a, count = 1;
    cin >> a;
    long ra = reverse(a);

    while (reverse(a + ra) != a + ra) {
        a = a + ra;
        ra = reverse(a);
        count++;
    }

    cout << count << " " << a + ra << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) runOnce();
    return 0;
}