#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void run() {
    unordered_map<char, int> hashtable;
    int k;
    cin >> k;

    char token;
    int value;
    while (k--) {
        cin >> token >> value;
        hashtable[token] = value;
    }
    string line;
    long lines;
    int earnings = 0;
    cin >> lines;
    cin.get(); // Consume \n
    while (lines--) {
        getline(cin, line);
        for (auto c: line) {
            if (hashtable.find(c) != hashtable.end()) {
                earnings += hashtable[c];
            }
        }
    }

    string result = to_string(earnings);
    while (result.size() < 3) {
        result.insert(0, "0");
    }
    result.insert(result.size() - 2, ".");
    result.append("$");
    cout << result << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}