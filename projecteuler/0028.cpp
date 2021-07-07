#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n = 1;
   int length = 0;
   long long sum = 1;
   while (n < 1001 * 1001) {
       length += 2;
       for (int i = 0; i < 4; ++i) {
           n += length;
           sum += n;
       }
   }
   printf("%lld\n", sum);
}