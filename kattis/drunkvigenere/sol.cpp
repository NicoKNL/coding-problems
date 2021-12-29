#include <bits/stdc++.h>

using namespace std;

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getIndex(char c)
{
    return c - 'A';
}

char offsetChar(char c, int offset)
{
    int i = getIndex(c) + 26;
    i += offset;
    i %= 26;
    return abc[i];
}

int main()
{
    string ciphertext, key;
    cin >> ciphertext >> key;

    for (int i = 0; i < ciphertext.length(); ++i)
    {
        int offset = getIndex(key[i]);

        if (i % 2 == 0)
            cout << (char)offsetChar(ciphertext[i], -offset);
        else
            cout << (char)offsetChar(ciphertext[i], offset);
    }

    cout << endl;

    return 0;
}