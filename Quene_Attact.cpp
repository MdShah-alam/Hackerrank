#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the number of squares the queen can attack
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> &obstacles) {
    // Directions in which queen can attack: (row offset, col offset)
    vector<pair<int, int>> directions = {
        {0, 1},   // right
        {0, -1},  // left
        {1, 0},   // up
        {-1, 0},  // down
        {1, 1},   // up-right diagonal
        {1, -1},  // up-left diagonal
        {-1, 1},  // down-right diagonal
        {-1, -1}  // down-left diagonal
    };

    // Maximum distances in each direction without obstacles
    int right = n - c_q;
    int left = c_q - 1;
    int up = n - r_q;
    int down = r_q - 1;
    int upRight = min(up, right);
    int upLeft = min(up, left);
    int downRight = min(down, right);
    int downLeft = min(down, left);

    // Adjust maximum distances based on obstacles
    for (int i = 0; i < k; i++) {
        int r_o = obstacles[i][0];
        int c_o = obstacles[i][1];

        // Obstacle is in the same row as the queen
        if (r_o == r_q) {
            if (c_o > c_q) {
                right = min(right, c_o - c_q - 1); // Obstacle to the right
            } else if (c_o < c_q) {
                left = min(left, c_q - c_o - 1); // Obstacle to the left
            }
        }
        // Obstacle is in the same column as the queen
        else if (c_o == c_q) {
            if (r_o > r_q) {
                up = min(up, r_o - r_q - 1); // Obstacle above
            } else if (r_o < r_q) {
                down = min(down, r_q - r_o - 1); // Obstacle below
            }
        }
        // Obstacle is on the same diagonal as the queen
        else if (abs(r_o - r_q) == abs(c_o - c_q)) {
            if (r_o > r_q && c_o > c_q) {
                upRight = min(upRight, r_o - r_q - 1); // Obstacle in the up-right diagonal
            } else if (r_o > r_q && c_o < c_q) {
                upLeft = min(upLeft, r_o - r_q - 1); // Obstacle in the up-left diagonal
            } else if (r_o < r_q && c_o > c_q) {
                downRight = min(downRight, r_q - r_o - 1); // Obstacle in the down-right diagonal
            } else if (r_o < r_q && c_o < c_q) {
                downLeft = min(downLeft, r_q - r_o - 1); // Obstacle in the down-left diagonal
            }
        }
    }

    // Total number of squares the queen can attack
    int totalAttackSquares = right + left + up + down + upRight + upLeft + downRight + downLeft;
    return totalAttackSquares;
}

int main() {
    int n, k;
    cin >> n >> k; // Board size and number of obstacles
    int r_q, c_q;
    cin >> r_q >> c_q; // Queen's position

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1]; // Obstacles' positions
    }

    // Call the function and print the result
    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;

    return 0;
}

