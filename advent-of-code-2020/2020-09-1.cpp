#include <bits/stdc++.h>
using namespace std;

vector<long long> numbers;

bool validNext(long long target, int start, int end) 
{
    for (int i = start; i < end - 1; ++i) {
        for (int j = start + 1; j < end; ++j) {
            if (i != j && numbers[i] + numbers[j] == target) return true;
        }
    }
    return false;
}

void findWeaknessExtremes(int start, int end)
{
    sort(numbers.begin() + start, numbers.begin() + end);
    cout << numbers[start] << ", " << numbers[end] << endl;
}

void findWeakness(long long target, int start, int end)
{
    for (int k = 2; k <= 25; ++k) {
        for (int i = start; i < end - k; ++i) {
            long long sum = 0;
            for (int j = i; j < i + k; ++j) {
                sum += numbers[j]; 
            }
            if (sum == target) {
                findWeaknessExtremes(i, i + k);
            }
        }
    }
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/09.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    while (getline(infile, line)) {
        long long n = stoll(line);

        if (numbers.size() >= 25) {
            int start = numbers.size() - 25;
            int end = numbers.size();
            if (!validNext(n, start, end)) {
                cout << n << endl;
                break;
            }
        }

        numbers.push_back(n);
    }
}
