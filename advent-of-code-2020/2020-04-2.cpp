#include <bits/stdc++.h>
using namespace std;

struct Passport
{
    string byr;
    string iyr;
    string eyr;
    string hgt;
    string hcl;
    string ecl;
    string pid;
    string cid;

    void print()
    {
        cout << endl;
        cout << "Passport" << endl;
        cout << "--------" << endl;
        cout << "byr = " << byr << endl;
        cout << "iyr = " << iyr << endl;
        cout << "eyr = " << eyr << endl;
        cout << "hgt = " << hgt << endl;
        cout << "hcl = " << hcl << endl;
        cout << "ecl = " << ecl << endl;
        cout << "pid = " << pid << endl;
        cout << "cid = " << cid << endl;
        cout << endl;
    }
};

int validatePassport(Passport p)
{
    regex re_byr("19[2-9][0-9]|200[0-2]");
    if (!regex_match(p.byr, re_byr)) return 0;

    regex re_iyr("201[0-9]|2020");
    if (!regex_match(p.iyr, re_iyr)) return 0;

    regex re_eyr("202[0-9]|2030");
    if (!regex_match(p.eyr, re_eyr)) return 0;

    regex re_hgt("(1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in");
    if (!regex_match(p.hgt, re_hgt)) return 0;

    regex re_hcl("#([0-9]|[a-f]){6}");
    if (!regex_match(p.hcl, re_hcl)) return 0;

    regex re_ecl("amb|blu|brn|gry|grn|hzl|oth");
    if (!regex_match(p.ecl, re_ecl)) return 0;

    regex re_pid("[0-9]{9}");
    if (!regex_match(p.pid, re_pid)) return 0;

    return 1;
}

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/04.txt");
    if (!infile.is_open()) {
        return -1;
    }

    int valid_passports = 0;
    Passport p;
    string line = "";
    while (getline(infile, line)) {
        if (line.length() == 0) {
            valid_passports += validatePassport(p);
            p = Passport();
        };

        string kvpair = "";
        stringstream ss(line);
        while (getline(ss, kvpair, ' ')) {
            string key = kvpair.substr(0, kvpair.find(':'));
            string value = kvpair.substr(kvpair.find(':') + 1);

            if (key == "byr") p.byr = value;
            else if (key == "iyr") p.iyr = value;
            else if (key == "eyr") p.eyr = value;
            else if (key == "hgt") p.hgt = value;
            else if (key == "hcl") p.hcl = value;
            else if (key == "ecl") p.ecl = value;
            else if (key == "pid") p.pid = value;
            else if (key == "cid") p.cid = value;
        }
    }

    valid_passports += validatePassport(p);

    cout << valid_passports << endl;
}
