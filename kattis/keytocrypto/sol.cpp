#include <bits/stdc++.h>

using namespace std;

string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char decipher(char cipher, char key)
{
    int ci = cipher - 'A';
    int ki = key - 'A';

    int mi = (ci + 26 - ki) % 26;
    return ABC[mi];
}

int main()
{
    string ciphertext, key;

    cin >> ciphertext >> key;

    string message;

    for (int i = 0; i < ciphertext.length(); ++i)
    {
        char message_char = decipher(ciphertext[i], key[i]);
        message += message_char;
        key += message_char;
    }

    cout << message << endl;

    return 0;
}