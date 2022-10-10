#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    list<string> L;
    unordered_map<string, list<string>::iterator> M;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        M[s] = L.insert(L.end(), s);
    }

    int C;
    cin >> C;

    while (C--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "cut")
        {
            string a, b;
            cin >> a >> b;
            M[a] = L.insert(M[b], a);
        }
        else
        {
            string a;
            cin >> a;
            L.erase(M[a]);
        }
    }

    for (auto each : L)
        cout << each << '\n';
}