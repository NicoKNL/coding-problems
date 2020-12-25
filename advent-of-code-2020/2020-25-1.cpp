#include <bits/stdc++.h>
using namespace std;

long long pub_card = 17607508;
long long pub_door = 15065270;
long long mod = 20201227;

long long loop_size_card;
long long loop_size_door;

long long loopSize(long long n) {
    long long i = 1;
    long long tmp = 1;
    while (true) {
        tmp *= (long long) 7;
        tmp %= mod;
        if (tmp == n) break;
        ++i;
    }
    return i;
}

long long transform(long long subject, long long loop_size)
{
    long long tmp = 1;
    for (long long i = 1; i <= loop_size; ++i) {
        tmp *= (long long) subject;
        tmp %= mod;
    }
    return tmp;
}

int main() 
{
    loop_size_card = loopSize(pub_card);
    loop_size_door = loopSize(pub_door);
    cout << transform(pub_door, loop_size_card);
}
