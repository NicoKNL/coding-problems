#include <bits/stdc++.h>

using namespace std;

void reduce(vector<int> &nums, vector<char> &ops)
{
    for (int i = 0; i < ops.size(); ++i)
    {
        if (ops[i] == '*' || ops[i] == '/')
        {
            if (ops[i] == '*')
                nums[i + 1] = nums[i] * nums[i + 1];
            else
                nums[i + 1] = nums[i] / nums[i + 1];

            nums.erase(nums.begin() + i);
            ops.erase(ops.begin() + i);
            return;
        }
    }

    for (int i = 0; i < ops.size(); ++i)
    {
        if (ops[i] == '+')
            nums[i + 1] = nums[i] + nums[i + 1];
        else
            nums[i + 1] = nums[i] - nums[i + 1];

        nums.erase(nums.begin() + i);
        ops.erase(ops.begin() + i);
        return;
    }
}

int solve(vector<char> ops)
{
    vector<int> result = {4, 4, 4, 4};

    while (result.size() > 1)
    {
        reduce(result, ops);
    }

    return result[0];
}

int main()
{
    vector<char> ops = {'+', '-', '*', '/'};

    int n;
    cin >> n;

    while (n--)
    {
        int target;
        cin >> target;

        bool solved = false;
        for (int i = 0; i < 4 && !solved; ++i)
        {
            for (int ii = 0; ii < 4 && !solved; ++ii)
            {
                for (int iii = 0; iii < 4 && !solved; ++iii)
                {
                    vector<char> o = {ops[i], ops[ii], ops[iii]};
                    if (solve(o) == target)
                    {
                        solved = true;
                        printf("4 %c 4 %c 4 %c 4 = %d\n", o[0], o[1], o[2], target);
                    }
                }
            }
        }

        if (!solved)
            cout << "no solution" << endl;
    }

    return 0;
}