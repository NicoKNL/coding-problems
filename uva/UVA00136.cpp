#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool isValid(int n) {
   while (n % 2 == 0) n /= 2;
   while (n % 3 == 0) n /= 3;
   while (n % 5 == 0) n /= 5;
   return n == 1;
}

int main() {
//    int counter = 2;
//    int i = 3;
//    while (true) {
//        bool valid = isValid(i);
//
//        if (valid) {
//            counter++;
//            printf("%d: %d\n", counter, i);
//            if (counter == 1500) {
//                break;
//            }
//        }
//        i++;
//    }

    printf("The 1500'th ugly number is 859963392.\n");

    return 0;
}