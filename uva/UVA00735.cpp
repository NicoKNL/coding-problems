#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int score, count;
    vi scores;
    vi subscore;
    vvi valid_scores;
    scores.push_back(0);  // miss / no-throw
    scores.push_back(50); // Bullseye
    for (int i = 1; i <= 20; i++) {
        scores.push_back(i);
        scores.push_back(2 * i);
        scores.push_back(3 * i);
    }

    sort(scores.begin(), scores.end());
    scores.erase(unique(scores.begin(), scores.end()), scores.end());

    while (cin >> score) {
        if (score <= 0) break;
        valid_scores.clear();

        for (int i = 0; i < scores.size(); i++) {
            score -= scores[i];
            if (score < 0) {
                score += scores[i];
                continue;
            }
            for (int j = 0; j < scores.size(); j++) {
                score -= scores[j];
                if (score < 0) {
                    score += scores[j];
                    continue;
                }
                for (int k = 0; k < scores.size(); k++) {
                    score -= scores[k];
                    if (score < 0) {
                        score += scores[k];
                        continue;
                    }

                    if (score == 0) {
                        subscore = {scores[i], scores[j], scores[k]};
                        sort(subscore.begin(), subscore.end());
                        valid_scores.push_back(subscore);
                    }
                    score += scores[k];
                }
                score += scores[j];
            }
            score += scores[i];
        }
        count = valid_scores.size();

        if (count == 0) {
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
        } else {
            sort(valid_scores.begin(), valid_scores.end());
            valid_scores.erase(unique(valid_scores.begin(), valid_scores.end()), valid_scores.end());
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << valid_scores.size() << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << count << "." << endl;
        }
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}