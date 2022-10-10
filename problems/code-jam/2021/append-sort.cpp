#include<bits/stdc++.h>

using namespace std;

int getDigitCount(unsigned long long n)
{
    unsigned long long test = 9;
    int count = 1;

    while (test < n)
    {
        test *= 10;
        test +=  9;
        ++count;
    }

    return count;
}

pair<int, unsigned long long> resolve(unsigned long long a, unsigned long long b)
{
    int digit_count_a = getDigitCount(a);
    int digit_count_b = getDigitCount(b);
    
    int diff = digit_count_a - digit_count_b;
    if (diff > 0) b *= pow(10, diff); 
    
    if (a >= b) {
        unsigned long long tmp = a - b + 1;
        int digit_count_tmp = getDigitCount(tmp);
        
        if (digit_count_tmp > diff)
        {
            b *= 10;
            ++diff;
        }
        else
        {
            b += tmp;
        }
    }

    return make_pair(diff, b);
}

int calculateSortingCost(vector<unsigned long long> & v)
{
    int cost = 0;

    for (int i = 1; i < v.size(); ++i)
    {
         if (v[i] <= v[i - 1])
         {
             pair<int, unsigned long long> fix = resolve(v[i - 1], v[i]);
             cost += fix.first;
             v[i] = fix.second;
         }
    }

    return cost;
}

void solve()
{
    int N;
    cin >> N;

    vector<unsigned long long> numbers(N);
    vector<unsigned long long> orig_numbers(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
        orig_numbers[i] = numbers[i];
    }

    cout << calculateSortingCost(numbers) << endl;

    for (int i = 0; i < N; ++i)
    {
        cout << orig_numbers[i] << " " << numbers[i] << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    int c = 1; 

    while (T--)
    {
        cout << "Case #" << c << ": ";
        solve();
        cout << endl;
        c++;
    }
}
// 799
// 79
