#include <bits/stdc++.h>

using namespace std;

bool isUnknown(const unordered_map<string, long long> &MEM, const vector<string> &V)
{
    for (auto each : V)
        if (MEM.find(each) == MEM.end())
            return true;

    return false;
}

void output(const unordered_map<string, long long> &MEM, const vector<string> &V, const vector<char> &ops, long long result)
{
    for (int i = 0; i < V.size(); ++i)
    {
        if (i > 0)
            cout << " ";

        cout << V[i] << " " << ops[i];
    }

    for (auto each : MEM)
    {
        if (each.second == result)
        {
            cout << " " << each.first << endl;
            return;
        }
    }

    cout << " unknown" << endl;
}

void resolve(unordered_map<string, long long> &MEM, const vector<string> &V, const vector<char> &ops)
{
    bool unknown = isUnknown(MEM, V);

    if (isUnknown(MEM, V))
    {
        output(MEM, V, ops, LONG_LONG_MAX);
    }
    else
    {
        long long result = MEM[V[0]];

        for (int i = 1; i < V.size(); ++i)
        {
            long long B = MEM[V[i]];

            if (ops[i - 1] == '+')
                result += B;
            else
                result -= B;
        }

        output(MEM, V, ops, result);
    }
}

int main()
{
    string s;

    unordered_map<string, long long> MEM;

    while (cin >> s)
    {
        if (s == "def")
        {
            string address;
            int value;
            cin >> address >> value;

            MEM[address] = value;
        }

        if (s == "calc")
        {
            vector<string> V;
            vector<char> ops;

            string address;
            char op;
            while (cin >> address >> op)
            {
                V.push_back(address);
                ops.push_back(op);

                if (op == '=')
                {
                    resolve(MEM, V, ops);
                    break;
                }
            }
        }

        if (s == "clear")
            MEM.clear();
    }

    return 0;
}