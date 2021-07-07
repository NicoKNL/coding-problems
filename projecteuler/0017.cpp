#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> dict = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"},
        {100, "hundred"},
        {1000, "thousand"},
};

int main()
{
    int total = 0;
    for (int i = 1; i <= 1000; ++i) {
        int sum = 0;
        int tmp = i;
        bool hundreds = false;
        if (tmp == 1000) {
            sum += dict[1].length(); // one
            sum += dict[1000].length(); // thousand
            tmp -= 1000;
        }

        if (tmp >= 100) {
            sum += dict[tmp / 100].length();
            sum += dict[100].length();
            tmp -= (tmp / 100) * 100;
            hundreds = true;
        }

        if (hundreds && tmp > 0) {
            sum += 3; // and
        }

        if (tmp >= 20) {
            sum += dict[(tmp / 10) * 10].length();
            tmp -= (tmp / 10) * 10;
        }

        if (tmp >= 1) {
            sum += dict[tmp].length();
        }
        total += sum;
        printf("%d, %d\n", i, sum);
    }
    printf("total: %d\n", total);
}
