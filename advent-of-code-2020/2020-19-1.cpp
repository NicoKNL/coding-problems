#include <bits/stdc++.h>
using namespace std;

int a_key = 97;
int a = -1;

int b_key = 2;
int b = -2;

unordered_map<int, vector<vector<int>>> rules;
int max_word_length = 0;
set<string> words;
set<string> valid_words;
string last_word;
unordered_map<string, string> memo;

void printWord(vector<int> & word)
{
    // cout << "word: ";
    // for (int w : word) {
    //     cout << w << " ";
    // } cout << endl;
}

bool generateWordsUpToLength(vector<int> & word)
{
    printWord(word);
    string s_word = "";
    for (int w : word) {
        s_word += to_string(w);
        s_word += ',';
    }
    // Too long anyway
    if (word.size() > max_word_length) {
        return false;
    } else if (memo.find(s_word) != memo.end()) {
        last_word = memo[s_word];
        return true;
    }

    // Test if already a word
    bool complete_word = true;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == a || word[i] == b);
        else {
            complete_word = false;
            break;
        }
    }
    if (complete_word) {
        string w;
        for (int each : word) {
            if (each == a) w += 'a';
            else w += 'b';
        }
        valid_words.insert(w);
        cout << w << endl;
        last_word = w;
        return true;
    }

    // Go deeper
    vector<int> next_word = word;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == a || word[i] == b) continue; 
        else {
            for (int j = 0; j < rules[word[i]].size(); ++j) {
                // do
                next_word.erase(next_word.begin() + i, next_word.begin() + i + 1);
                next_word.insert(next_word.begin() + i, rules[word[i]][j].begin(), rules[word[i]][j].end());
                bool found = generateWordsUpToLength(next_word);
                if (found) {
                    string s_next_word = "";
                    for (int w : next_word) {
                        s_next_word += to_string(w);
                        s_next_word += ',';
                    }
                    if (memo.find(s_next_word) == memo.end()) {
                        memo[s_next_word] = last_word;
                    }
                }
                // undo
                next_word.erase(next_word.begin() + i, next_word.begin() + i + rules[word[i]][j].size());
                next_word.insert(next_word.begin() + i, word[i]);
            }
        }
    }
    return false;
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

    generateWordsUpToLength(rules[0][0]); 

    cout << valid_words.size() << endl;

    int count = 0;
    for (string w : words) {
        if (valid_words.find(w) != valid_words.end()) ++count;
    }

    cout << count << endl;
}
