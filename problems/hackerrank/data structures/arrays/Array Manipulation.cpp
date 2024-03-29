#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<vector<int>> start;
    vector<vector<int>> end;
    vector<long> results {0};
    results.reserve(2*n);

    for (vector<int> query : queries) {
        start.push_back(vector<int>{query[0], query[2]});
        end.push_back(vector<int>{query[1], query[2]});
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    long current_result = 0;
    while (i < queries.size()) {
        if (start[i][0] <= end[j][0]) {
            current_result += start[i][1];
            i++;
        } else {// if (start[i][0] > end[j][0]) {
            current_result -= end[j][1];
            j++;
        }
        results.push_back(current_result);
    }

    long max_sum = 0;
    for (long sum : results) {
        max_sum = sum > max_sum ? sum : max_sum;
    }

    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
