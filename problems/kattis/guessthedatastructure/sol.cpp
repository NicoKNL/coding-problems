#include <bits/stdc++.h>

using namespace std;

bool isStacklike(vector<int> instructions, vector<int> args)
{
    stack<int> S;

    for (int i = 0; i < instructions.size(); ++i)
    {
        if (instructions[i] == 1)
            S.push(args[i]);
        else
        {
            if (S.empty())
                return false;
            int tmp = S.top();
            S.pop();

            if (tmp != args[i])
                return false;
        }
    }

    return true;
}

bool isQueuelike(vector<int> instructions, vector<int> args)
{
    queue<int> S;

    for (int i = 0; i < instructions.size(); ++i)
    {
        if (instructions[i] == 1)
            S.push(args[i]);
        else
        {
            if (S.empty())
                return false;
            int tmp = S.front();
            S.pop();

            if (tmp != args[i])
                return false;
        }
    }

    return true;
}

bool isPriorityQueuelike(vector<int> instructions, vector<int> args)
{
    priority_queue<int> S;

    for (int i = 0; i < instructions.size(); ++i)
    {
        if (instructions[i] == 1)
            S.push(args[i]);
        else
        {
            if (S.empty())
                return false;
            int tmp = S.top();
            S.pop();

            if (tmp != args[i])
                return false;
        }
    }

    return true;
}

int main()
{
    int n;

    while (cin >> n)
    {
        vector<int> instructions(n, 0);
        vector<int> args(n, 0);

        for (int i = 0; i < n; ++i)
            cin >> instructions[i] >> args[i];

        vector<bool> results = {
            isStacklike(instructions, args),
            isQueuelike(instructions, args),
            isPriorityQueuelike(instructions, args),
        };

        int result_count = accumulate(results.begin(), results.end(), 0);
        if (result_count == 0)
            cout << "impossible" << endl;
        else if (result_count > 1)
            cout << "not sure" << endl;
        else if (results[0])
            cout << "stack" << endl;
        else if (results[1])
            cout << "queue" << endl;
        else // results[2]
            cout << "priority queue" << endl;
    }

    return 0;
}