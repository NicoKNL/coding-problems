#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void oneRun() {
    int floors;
    cin >> floors;

    /** Construct array to store how many want to exit at floor N */
    int people[floors+1]; // + 1 so we can start at 1 for this DP solution
    people[0] = 0;
    for (int i = 1; i <= floors; i++) {
        cin >> people[i];
    }

    /** Construct array storing the number of people above a floor N */
    int people_above[floors+1] = {0};
    for (int i = floors - 1; i >= 0; i--) {
        people_above[i] = people_above[i+1] + people[i+1];
    }

    int result[floors+1] = {0};  // Floor 0 does not exist, hence we never stop here. Used as check to see if not stopping before a current floor N is more effective than stopping somewhere else in between.
    result[1] = people_above[1]; // Floor 1 trivially has all people above it getting angry
    for (int floor = 2; floor <= floors; floor++) {
        int minimum_anger = INT_MAX - 1;

        /** For counting the anger from walking people in between the previous and current floor */
        int max_anger_between = 0;
        int people_walking = 0;

        for (int i = 1; i < floor; i++)
        {
            people_walking += people[i];
            max_anger_between += people_walking;
        }

        int dist;
        for (int prev_floor = 0; prev_floor < floor; prev_floor++)
        {
            /** Removing people we went past, they have already been serviced and don't have to walk down `dist` times*/
            dist = floor - prev_floor;
            max_anger_between -= dist * people[prev_floor];

            /** Calculating a new possible minimum anger */
            int anger = result[prev_floor] + people_above[floor] + max_anger_between;
            if (anger < minimum_anger) {
                minimum_anger = anger;
            }
        }
        result[floor] = minimum_anger;
    }

    cout << result[floors] << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}

/** TEST CASES
 *
1
5
0 3 0 0 7

 output: 7


1
5
0 0 3 0 7

 output: 6


1
10
3 1 4 1 5 9 2 6 5 3

 output: 67


1
10
1 2 3 4 5 6 7 8 9 10

 output: 101

1
9
1 0 1 0 1 0 1 0 1

 output: 8

1
1
100

 output: 0
 */