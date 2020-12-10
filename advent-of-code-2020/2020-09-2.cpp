#include <bits/stdc++.h>
using namespace std;
#define PREAMBLE 25

vector<long long> numbers;
long long target;

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
    sort(numbers.begin() + start, numbers.begin() + end + 1);
    cout << end - start << " : "  << numbers[start] << " + " << numbers[end] << " = " << numbers[start] + numbers[end] << endl;
}

void findWeakness(long long target, int start, int end)
{
    for (int k = 1; k <= PREAMBLE; ++k) {
        for (int i = start; i < end - k; ++i) {
            long long sum = 0;
            for (int j = i; j <= i + k; ++j) {
                // cout << numbers[j] << ", ";
                sum += numbers[j]; 
            }
            // cout << endl;
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

        if (numbers.size() >= PREAMBLE) {
            int start = numbers.size() - PREAMBLE;
            int end = numbers.size();
            if (!validNext(n, start, end)) {
                target = n;
                cout << n << endl;
                // findWeakness(n, start, end);
            }
        }

        numbers.push_back(n);
    }

    findWeakness(target, 0, numbers.size());
}
