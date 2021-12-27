#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string end;
    string ciphertext;

    cin >> end >> ciphertext;

    string key = ciphertext + end;
    string abc = "abcdefghijklmnopqrstuvwxyz";

    /**
     *     |
     * ................again = k
     * pirpumsemoystoal = b = ciphertext
     * ...........again = plaintext
     */
    for (int i = key.length() - end.length() - 1; i >= 0; --i)
    {
        key[i] = abc[(key[i] - key[i + end.length()] + 52) % 26];
    }

    cout << key.substr(n) << endl;

    return 0;
}