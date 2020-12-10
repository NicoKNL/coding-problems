#include <bits/stdc++.h>
using namespace std;

struct Bag
{
    string color;
    vector<shared_ptr<Bag>> children;
};

void printMap(const unordered_map<string, shared_ptr<Bag>> & m)
{
    cout << "log of map: " << endl;
    cout << "----------- " << endl;
    for (auto entry : m) {
        cout << entry.first << " = " << entry.second->children.size() << endl;
    }
    cout << "----------- " << endl << endl;
}

int main() {
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/07.txt");
    if (!infile.is_open()) {
        return -1;
    }

    unordered_map<string, shared_ptr<Bag>> bags;
    printMap(bags);

    string line = "";
    while (getline(infile, line)) {
        cout << line << endl << endl;
        string current_color;
        
        regex source_color("^[^\\s]+\\s[^\\s]+", regex_constants::ECMAScript);
        auto words_begin = sregex_iterator(line.begin(), line.end(), source_color);
        auto words_end = sregex_iterator();
        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            string match_str = match.str();
            
            current_color = match_str;
            if (bags.find(current_color) == bags.end()) {
                bags[match_str] = make_shared<Bag>();
                bags[match_str]->color = current_color;
            }
            break;
        } 
        printMap(bags);

        regex nested_bags("\\d\\s[^\\s]+\\s[^\\s]+", regex_constants::ECMAScript);
        words_begin = sregex_iterator(line.begin(), line.end(), nested_bags);
        words_end = sregex_iterator();
        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            string match_str = match.str();

            int count = stoi(match_str.substr(0, 1));
            match_str = match_str.substr(2);

            if (bags.find(match_str) != bags.end()) {
                // bags[current_color]->children.emplace_back({bags[match_str], t});
                bags[match_str]->children.emplace_back(bags[current_color]);
            } else {
                bags[match_str] = make_shared<Bag>();
                bags[match_str]->color = match_str;
                bags[match_str]->children.emplace_back(bags[current_color]);
            }
        }
    }

    string source_color = "shiny gold";
    unordered_set<string> containers;

    queue<shared_ptr<Bag>> Q;
    Q.push(bags[source_color]);
    while(!Q.empty()) {
        shared_ptr<Bag> bag = Q.front();
        Q.pop();

        for (shared_ptr<Bag> child_bag : bag->children) {
            containers.insert(child_bag->color);
            Q.push(child_bag);
        }
    }   

    cout << containers.size() << endl;
}
