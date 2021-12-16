#include <bits/stdc++.h>

using namespace std;

int bs2int(string s)
{
    int result = 0;

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '1')
            result += (1 << i);
    }

    return result;
}

struct Packet
{
    int version;
    int type;
    int length_type_ID;
    int packet_count;
    int packet_length;
    vector<string> subpackets;
    string payload;

    Packet(string bits)
    {
        int POL = 0; // start of payload

        version = bs2int(bits.substr(POL, 3));
        POL += 3;

        type = bs2int(bits.substr(POL, 3));
        POL += 3;

        if (type != 4)
        {
            length_type_ID = bits[POL] - '0';
            ++POL;

            if (length_type_ID == 0)
            {
                packet_count = bs2int(bits.substr(POL, 15));
                POL += 15;
                payload = bits.substr(POL);
            }
            else
            { //1
                packet_length = bs2int(bits.substr(POL, 11));
                POL += 11;
                payload = bits.substr(POL, packet_length);
            }
        }
        else
        {
            payload = bits.substr(POL);
        }
    }
};

unordered_map<char, string>
    M{
        {'0', "0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
        {'8', "1000"},
        {'9', "1001"},
        {'A', "1010"},
        {'B', "1011"},
        {'C', "1100"},
        {'D', "1101"},
        {'E', "1110"},
        {'F', "1111"}};

string parseHex(string s)
{
    string bits;

    for (char c : s)
    {
        bits += M[c];
    }

    return bits;
}

unsigned long long getValueType4(string s)
{
    vector<string> blocks;
    string tmp;
    for (int i = 0; i < s.length(); ++i)
    {
        if (tmp.length() == 5)
        {
            blocks.push_back(tmp);
            tmp = "";
        }

        tmp += s[i];
    }

    string s_num;

    for (string block : blocks)
    {
        s_num += block.substr(1);

        if (block[0] == '0')
            break;
    }
    cout << "string_num: " << s_num << endl;

    unsigned long long n = 0;

    reverse(s_num.begin(), s_num.end());
    for (unsigned long long i = 0; i < s_num.length(); ++i)
    {
        unsigned long long one = 1;

        if (s_num[i] == '1')
            n += (one << i);
    }

    return n;
}

int main()
{
    string line;
    getline(cin, line);

    string bitstring = parseHex(line);
    cout << bitstring << endl;

    Packet p(bitstring);

    queue<Packet> Q;
    Q.push(p);

    unsigned long long result = 0;
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();

        result += p.version;

        if (p.type == 4)
            continue;

        if (p.length_type_ID == 0)
    }
    cout << p.version << endl;
    cout << p.type << endl;
    // cout << getValueType4(p.payload) << endl;
    return 0;
}