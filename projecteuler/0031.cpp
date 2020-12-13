#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
int counter = 0;
int target_value = 200;

void bruteforce(int current_sum, int min_value)
{
   if (current_sum == target_value) {
       counter++;
       cout << counter << endl;
   } else {
       for (int coin : coins) {
           if (coin < min_value) continue;

           current_sum += coin;
           if (current_sum <= target_value) {
               bruteforce(current_sum, coin);
           }
           current_sum -= coin;
       }
   }
}

int main()
{
    bruteforce(0, 1);
}
