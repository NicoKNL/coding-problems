#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> result; 
vector<string> mapped_ingredients;
unordered_map<string, vector<string>> M; // allergen -> {ingredient1, ingredient2, ...}
unordered_map<string, int> C; // counter

string cleanup(string & s)
{
    s = s.substr(10, s.length() - 11);
    string cleaned;
    for (char c : s) {
        if (c == ',') continue;
        cleaned += c;
    }
    return cleaned; 
}

vector<string> split(string & s)
{
    vector<string> result;

    stringstream ss(s);
    string each;
    while (ss >> each) {
        result.push_back(each);
    }
    return result;
}

vector<string> _intersect(vector<string> & a, vector<string> & b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<string> result(1000);
    auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(it - result.begin());
    return result;
}

vector<string> _union(vector<string> & a, vector<string> & b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<string> result(1000);
    auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(it - result.begin());
    return result;
}

vector<string> _difference(vector<string> & a, vector<string> & b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<string> result(1000);
    auto it = set_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(it - result.begin());
    return result;
}

void update(vector<string> ingredients, vector<string> allergens)
{
    for (string ingredient : ingredients) {
        C[ingredient]++;
    }

    for (string allergen : allergens) {
        if (M.find(allergen) == M.end()) {
            M[allergen] = ingredients;
        } else {
            vector<string> in_common = _intersect(M[allergen], ingredients);
            M[allergen] = in_common;
        }
    }
}

bool reduce()
{
    for (auto & entry : M) {
        if (entry.second.size() == 1) {
            for (auto & other : M) {
                if (entry.first == other.first) continue;
                auto it = find(other.second.begin(), other.second.end(), entry.second[0]);
                if (it != other.second.end()) {
                    other.second.erase(it);
                    return true;
                }
            }
        }
    }
    return false;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/21y.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<string> all_ingredients;
    string line;
    while (getline(infile, line)) {
        string s_ingredients = line.substr(0, line.find("("));
        string s_allergens = line.substr(line.find("("));
        s_allergens = cleanup(s_allergens);

        vector<string> ingredients = split(s_ingredients);
        vector<string> allergens = split(s_allergens);

        all_ingredients = _union(all_ingredients, ingredients); 

        update(ingredients, allergens);
    }


    bool reducing = true;
    while (reducing) {
        reducing = reduce();
    }

    for (auto entry : M) {
        mapped_ingredients.push_back(entry.second[0]);
    }
    
    int result = 0;
    vector<string> unmapped_ingredients = _difference(all_ingredients, mapped_ingredients);
    for (string ingredient : unmapped_ingredients) {
        result += C[ingredient];
    }
    cout << result << endl;
}
