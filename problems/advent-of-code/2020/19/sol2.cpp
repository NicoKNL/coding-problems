#include <bits/stdc++.h>
using namespace std;

#define MAX_DEPTH 5

int a_key = 97;
int b_key = 2;

const int a = -1;
const int b = -2;
const int ior = -3;
const int ileft = -4;
const int iright = -5;

unordered_map<int, vector<vector<int>>> rules;
int max_word_length = 0;
set<string> words;
list<int> super_rule;
string r;
map<int, string> replacements;

void generateSuperRegex()
{
    bool done = false;
    while (!done) {
        done = true;
        auto it = super_rule.begin();
        
        while (it != super_rule.end()) {
            if (*it == a || *it == b || *it == ior || *it == ileft || *it == iright) {
                ++it;
                continue;
            } else {
                done = false;
                super_rule.insert(it, ileft);

                vector<vector<int>> rule = rules[*it];
                for (int i = 0; i < rule.size(); ++i) {
                    for (int each : rule[i]) {
                        super_rule.insert(it, each);
                    }
                    if (rule.size() >= 2 && i < rule.size() - 1) {
                        super_rule.insert(it, ior);
                    }
                }

                super_rule.insert(it, iright);
                super_rule.erase(it);
                break;
            }
        }
    }
}

void convertToString()
{
    r = "";
    for (int each : super_rule) {
        switch (each) {
            case a:
                r += 'a';
                break;
            case b:
                r += 'b';
                break;
            case ior:
                r += '|';
                break;
            case ileft:
                r += '(';
                break;
            case iright:
                r += ')';
                break;
            case 8:
                r += "(";
                r += replacements[8];
                r += ")+"; 
                break;
            case 11:
                r += "(";
                r += replacements[11];
                r += ")";
                break;
        }  
    }
}

string generateRegex(int start)
{
    super_rule = {start};
    generateSuperRegex();
    convertToString();
    return r;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/19.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    while (getline(infile, line)) {
        if (line[0] == 'a' || line[0] == 'b') {
            max_word_length = max(max_word_length, (int) line.length());
            words.insert(line);
        } else if (line.length() > 1) {
            int key = stoi(line.substr(0, line.find(":")));            
            
            if (key == a_key) { // "a"
                rules[key] = {{a}};
                continue;
            } else if (key == b_key) {
                rules[key] = {{b}};
                continue;
            }

            string s_rules = line.substr(line.find(":"));
            stringstream ss(s_rules);
            string s_rule;
            vector<vector<int>> value;
            while (getline(ss, s_rule, '|')) {
                vector<int> rule;
                regex regexp("[0-9]+");
                smatch m;
                while (regex_search(s_rule, m, regexp)) {
                    for (string each : m) {
                        rule.push_back(stoi(each));
                    }
                    s_rule = m.suffix().str();
                }
                value.push_back(rule);
            }

            rules[key] = value;
        }
    }

    vector<vector<int>> rule_override;
    for (int i = 1; i <= MAX_DEPTH; ++i) {
        vector<int> rule;
        for (int j = 1; j <= i; ++j) {
            rule.push_back(42);
        }
        for (int j = 1; j <= i; ++j) {
            rule.push_back(31);
        }
        rule_override.push_back(rule);
    }
    rules[11] = rule_override;

    rule_override = {};
    for (int i = 1; i <= MAX_DEPTH; ++i) {
        vector<int> rule;
        for (int j = 1; j <= i; ++j) {
            rule.push_back(42);
        }
        rule_override.push_back(rule);
    }
    rules[8] = rule_override;

    super_rule.push_back(0);
    generateSuperRegex();
    convertToString();

    regex regexp(r);
    smatch m;

    int count = 0;
    for (string w : words) {
        if (regex_match(w, m, regexp)) {
            ++count;
        }
    }

    cout << count << endl;
}
