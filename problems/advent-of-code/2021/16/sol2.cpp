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

unsigned long long extractLiteral(string &s)
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

    if (tmp.length() == 5 && blocks.size() == 0)
    {
        blocks.push_back(tmp);
    }

    s = s.substr(i);

    string s_num;

    for (string block : blocks)
    {
        s_num += block.substr(1);
    }

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

unsigned long long applyOp(int op, vector<unsigned long long> nums)
{
    unsigned long long result;
    switch (op)
    {
    case 0:
        result = 0;

        for (auto n : nums)
            result += n;

        return result;

    case 1:
        result = 1;

        for (auto n : nums)
            result *= n;

        return result;

    case 2:
        sort(nums.begin(), nums.end());
        return *nums.begin();

    case 3:
        sort(nums.begin(), nums.end());
        return *nums.rbegin();

    case 5:
        return nums[0] > nums[1];

    case 6:
        return nums[0] < nums[1];

    case 7:
        return nums[0] == nums[1];
    }
}

unsigned long long parse(string &bitstring)
{
    MODE mode = VERSION;
    int version;
    int type;
    unsigned long long literal_value;
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
            return literal_value;
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
            vector<unsigned long long> nums;

            while (total_length)
            {
                unsigned long long v = parse(bitstring);
                nums.push_back(v);
                total_length -= (init_length - bitstring.length());
                init_length = bitstring.length();
            }

            return applyOp(type, nums);
        }
        else if (mode == NUMPACKS)
        {
            num_packs = extractN(bitstring, 11);
            vector<unsigned long long> nums;
            for (int i = 0; i < num_packs; ++i)
            {
                unsigned long long v = parse(bitstring);
                nums.push_back(v);
            }

            return applyOp(type, nums);
        }
    }
}

int main()
{
    string line;
    getline(cin, line);

    string bitstring = parseHex(line);
    unsigned long long v = parse(bitstring);
    cout << v << endl;
    return 0;
}