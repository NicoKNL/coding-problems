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
    if (p.byr == "" || p.iyr == "" || p.eyr == "" ||
        p.hgt == "" || p.hcl == "" || p.ecl == "" ||
        p.pid == "") {
            return 0;
        }
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
