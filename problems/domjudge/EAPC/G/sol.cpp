
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int n = 100000;
    vector<bool> prime(n, true);
    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (prime[p])
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;

    unordered_set<string> PRIMES;
    for (int i = 10000; i < n; ++i)
        if (prime[i])
            PRIMES.insert(to_string(i));

    cout << "number of primes: " << PRIMES.size() << endl;
    int rounds;
    cin >> rounds;

    while (rounds--)
    {
        int start_round = 1;
        while (true)
        {
            // 31517
            string guess;

            if (start_round == 1)
            {
                guess = "54327";
                start_round = 2;
            }
            else if (start_round == 2)
            {
                guess = "16789";
                start_round = 3;
            }
            else
            {
                guess = *PRIMES.begin();
            }

            cout << guess << endl
                 << flush;

            string ans;
            cin >> ans;

            if (ans == "ggggg")
            {
                start_round = true;
                break;
            }

            for (int i = 0; i < ans.length(); ++i)
            {
                char c = ans[i];
                int c_count = count(ans.begin(), ans.end(), c);

                if (c == 'g')
                {
                    vector<string> remove;
                    for (auto each : PRIMES)
                    {
                        if (each[i] != guess[i])
                        {
                            remove.push_back(each);
                        }
                    }

                    for (auto each : remove)
                        PRIMES.erase(each);
                }
                else if ((c == 'w' && c_count > 1) || c == 'y')
                {
                    vector<string> remove;
                    for (auto each : PRIMES)
                    {
                        if (each[i] == guess[i])
                        {
                            remove.push_back(each);
                        }
                    }
                    for (auto each : remove)
                        PRIMES.erase(each);
                }
                else if (c == 'w' && c_count == 1)
                {
                    vector<string> remove;
                    for (auto each : PRIMES)
                    {
                        for (int ii = 0; ii < each.length(); ++ii)
                        {
                            if (each[ii] == c)
                            {
                                remove.push_back(each);
                                break;
                            }
                        }
                    }

                    for (auto each : remove)
                        PRIMES.erase(each);
                }
            }
            cout << PRIMES.size() << endl;
        }
    }

    return 0;
}