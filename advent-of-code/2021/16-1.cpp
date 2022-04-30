#include <bits/stdc++.h>

using namespace std;

int version_sum = 0;

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

string parseHex(string s)
{
    string bits;

    for (char c : s)
    {
        bits += M[c];
    }

    return bits;
}
enum MODE
{
    VERSION,
    TYPE,
    LITERAL,
    NONLITERAL,
    LENGTH,
    NUMPACKS,
};

int extractN(string &s, int n)
{
    int version = bs2int(s.substr(0, n));
    s = s.substr(n);
    return version;
}

int extractLiteral(string &s)
{
    vector<string> blocks;
    string tmp;
    int i = 0;
    for (; i < s.length(); ++i)
    {
        if (tmp.length() == 5)
        {
            blocks.push_back(tmp);
            if (tmp[0] == '0')
                break;
            tmp = "";
        }

        tmp += s[i];
    }

    s = s.substr(i);

    string s_num;

    for (string block : blocks)
    {
        s_num += block.substr(1);
    }

    int n = 0;

    reverse(s_num.begin(), s_num.end());
    for (int i = 0; i < s_num.length(); ++i)
    {
        if (s_num[i] == '1')
            n += (1 << i);
    }

    return n;
}

void parse(string &bitstring)
{
    MODE mode = VERSION;
    int version;
    int type;
    int literal_value;
    int length_type_id;
    int total_length;
    int num_packs;

    while (bitstring.length())
    {
        if (mode == VERSION)
        {
            version = extractN(bitstring, 3);
            version_sum += version;
            mode = TYPE;
        }
        else if (mode == TYPE)
        {
            type = extractN(bitstring, 3);

            if (type == 4)
            {
                mode = LITERAL;
            }
            else
            {
                mode = NONLITERAL;
            }
        }
        else if (mode == LITERAL)
        {
            literal_value = extractLiteral(bitstring);
            return;
        }
        else if (mode == NONLITERAL)
        {
            length_type_id = extractN(bitstring, 1);
            if (length_type_id == 0)
            {
                mode = LENGTH;
            }
            else
            {
                mode = NUMPACKS;
            }
        }
        else if (mode == LENGTH)
        {
            total_length = extractN(bitstring, 15);
            int init_length = bitstring.length();
            while (total_length)
            {
                parse(bitstring);
                total_length -= (init_length - bitstring.length());
                init_length = bitstring.length();
            }
            return;
        }
        else if (mode == NUMPACKS)
        {
            num_packs = extractN(bitstring, 11);
            for (int i = 0; i < num_packs; ++i)
            {
                parse(bitstring);
            }
            return;
        }
    }
}

int main()
{
    string line;
    getline(cin, line);

    string bitstring = parseHex(line);
    parse(bitstring);

    cout << version_sum << endl;
    return 0;
}