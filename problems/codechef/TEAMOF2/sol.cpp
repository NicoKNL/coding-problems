#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool pairSolvesAllFive(unordered_set<int> &s1, unordered_set<int> &s2)
{
    for (int i = 1; i <= 5; ++i)
    {
        if (s1.find(i) == s1.end() && s2.find(i) == s2.end())
        {
            return false;
        }
    }
    return true;
}

bool pairCanSolveAllFive(vector<unordered_set<int>> &scores)
{
    for (int s1 = 0; s1 < scores.size(); ++s1)
    {
        for (int s2 = s1 + 1; s2 < scores.size(); ++s2)
        {
            if (pairSolvesAllFive(scores[s1], scores[s2]))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<unordered_set<int>> student_scores;

        for (int i = 0; i < N; ++i)
        {
            unordered_set<int> scores;
            int K;
            cin >> K;

            for (int ii = 0; ii < K; ++ii)
            {
                int tmp;
                cin >> tmp;
                scores.insert(tmp);
            }

            student_scores.push_back(scores);
        }

        if (pairCanSolveAllFive(student_scores))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}