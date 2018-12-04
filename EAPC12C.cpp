#include <iostream>
#include <vector>

using namespace std;

// initialize all the sticker vectors
vector<vector<double>> stickers;

// Initialize the rotation matrices
vector<vector<double>> rotateX = {
        {1, 0, 0},
        {0, 0, -1},
        {0, 1, 0}
};

vector<vector<double>> rotateY = {
        {0, 0, 1},
        {0, 1, 0},
        {-1, 0, 0}
};

vector<vector<double>> rotateZ = {
        {0, -1, 0},
        {1, 0, 0},
        {0, 0, 1}
};


void initCube(void)
{
    stickers = {
        /** ENCODING
         * W = 0, Y = 1, R = 2, O = 3, G = 4, B = 5
         */
        // White stickers UP (Y+)
        {-1, 2, 1, 0} , {0, 2, 1, 0} , {1, 2, 1, 0},
        {-1, 2, 0, 0} ,                {1, 2, 0, 0},
        {-1, 2, -1, 0}, {0, 2, -1, 0}, {1, 2, -1, 0},

        // Yellow stickers DOWN (Y-)
        {-1, -2, 1, 1} , {0, -2, 1, 1} , {1, -2, 1, 1},
        {-1, -2, 0, 1} ,                 {1, -2, 0, 1},
        {-1, -2, -1, 1}, {0, -2, -1, 1}, {1, -2, -1, 1},

        // Red stickers FRONT (X+)
        {2, -1, 1, 2} , {2, 0, 1, 2} , {2, 1, 1, 2},
        {2, -1, 0, 2} ,                {2, 1, 0, 2},
        {2, -1, -1, 2}, {2, 0, -1, 2}, {2, 1, -1, 2},

        // Orange stickers BACK (X-)
        {-2, -1, 1, 3} , {-2, 0, 1, 3} , {-2, 1, 1, 3},
        {-2, -1, 0, 3} ,                 {-2, 1, 0, 3},
        {-2, -1, -1, 3}, {-2, 0, -1, 3}, {-2, 1, -1, 3},

        // Green stickers LEFT
        {-1, 1, 2, 4} , {0, 1, 2, 4} , {1, 1, 2, 4},
        {-1, 0, 2, 4} ,                 {1, 0, 2, 4},
        {-1, -1, 2, 4}, {0, -1, 2, 4}, {1, -1, 2, 4},

        // Blue stickers RIGHT
        {-1, 1, -2, 5} , {0, 1, -2, 5} , {1, 1, -2, 5},
        {-1, 0, -2, 5} ,                {1, 0, -2, 5},
        {-1, -1, -2, 5}, {0, -1, -2, 5}, {1, -1, -2, 5},
    };

}

vector<double> multiply(vector<vector<double>> & matrix, vector<double> & vec)
{
    vector<double> result;
    double sum;
    for (int row = 0; row < 3; row++) {
        sum = 0.0;
        for (int col = 0; col < 3; col++) {
            sum += matrix[col][row] * vec[col];
        }
        result.push_back(sum);
    }
    result.push_back(vec[3]);
    return result;
}

void run_command(string command, int n_times)
{
    vector<vector<double>> m;
    char dir = command.at(0);
    int check_index;
    double check_value;

    if (dir == 'U') {
        m = rotateY;
        check_index = 1;
        check_value = 2;
    } else if (dir == 'D') {
        m = rotateY;
        check_index = 1;
        check_value = -2;
        n_times *= 3; // Correct for orientation.
    } else if (dir == 'F') {
        m = rotateX;
        check_index = 0;
        check_value = 2;
    } else if (dir == 'B') {
        m = rotateX;
        check_index = 0;
        check_value = -2;
        n_times *= 3; // Correct for orientation.
    } else if (dir == 'L') {
        m = rotateZ;
        check_index = 2;
        check_value = 2;
    } else if (dir == 'R') {
        m = rotateZ;
        check_index = 2;
        check_value = -2;
        n_times *= 3; // Correct for orientation.
    }

    if (command.at(1) == '-') { // Check for negative
        n_times *= 3; // Rotating once to the left => 3x to the right.
    }

    n_times = n_times % 4;
    for (vector<double>& sticker : stickers) {
        if (sticker[check_index] == check_value || sticker[check_index] == check_value - (check_value / 2.0)) {
            for (int i = 0; i < n_times; i++) {
                sticker = multiply(m, sticker);
            }
        }
    }
}

char translate(double number)
{
    if (number == 0) {
        return 'w';
    } else if (number == 1) {
        return 'y';
    } else if (number == 2) {
        return 'r';
    } else if (number == 3) {
        return 'o';
    } else if (number == 4) {
        return 'g';
    } else {// if (number == 5) {
        return 'b';
    }
}

void oneRun()
{
    initCube();
    int n_commands;
    cin >> n_commands;

    string command;
    string previous_command;
    int command_count = 0;
    while (n_commands--) {
        cin >> command;
        if (previous_command.empty()) {
            previous_command = command;
            command_count++;
        }
        else if (command == previous_command) {
            command_count++;
        } else {
            run_command(previous_command, command_count % 4);

            previous_command = command;
            command_count = 1;
        }
    }
    run_command(previous_command, command_count % 4);

    // Finally check which vectors are relevant for output
    for (int row = -1; row < 2; row++) {
        for (int col = 1; col > -2; col--) {
            if (row == 0 && col == 0) {
                cout << 'w';
            } else { // Find the sticker
                for (vector<double>& sticker : stickers) {
                    if (sticker[0] == row && sticker[1] == 2 && sticker[2] == col) {
                        cout << translate(sticker[3]);
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}