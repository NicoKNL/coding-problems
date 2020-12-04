#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    string tmp = to_string(n);
    int start = 0;
    int end = tmp.size() - 1;

    while (start != end && start < end) {
        if (tmp[start] != tmp[end]) {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}

int main()
{
    int largest_palindrome = 1;
    for (int a = 1; a <= 999; ++a) {
        for (int b = 1; b <= 999; ++b) {
            if (isPalindrome(a * b) && a * b > largest_palindrome) {
                largest_palindrome = a * b;
            }
        }
    }
    printf("%d", largest_palindrome);
}
