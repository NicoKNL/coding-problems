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

// int dfs(shared_ptr<Bag> bag)
// {
//     if (bag->children.size() == 0) return 1;

//     int sum = 0;
//     for (auto child : bag->children) {
//         shared_ptr<Bag> c_bag = child.first;
//         int count = child.second;
//         count = count + count * dfs(c_bag);
//         // count *= dfs(c_bag);
//         sum += count;
//     }
//     return sum;
// }

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
                for (int i = 0; i < count; ++i) {
                    bags[current_color]->children.emplace_back(bags[match_str]);
                }
            } else {
                bags[match_str] = make_shared<Bag>();
                bags[match_str]->color = match_str;
                for (int i = 0; i < count; ++i) {
                    bags[current_color]->children.emplace_back(bags[match_str]);
                }
            }
        }
    }

    string source_color = "shiny gold";
    int sum = 0;

    queue<shared_ptr<Bag>> Q;
    Q.push(bags[source_color]);
    while(!Q.empty()) {
        shared_ptr<Bag> bag = Q.front();
        Q.pop();

        for (auto child : bag->children) {
            // containers.insert(child.first->color);
            Q.push(child);
            sum += 1;
        }
    }

    // cout << containers.size() << endl;
    cout << sum << endl;
}
