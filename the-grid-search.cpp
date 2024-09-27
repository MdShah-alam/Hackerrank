#include <iostream>
#include <vector>
using namespace std;

string gridSearch(vector<string>& G, vector<string>& P) {
    int R = G.size();          // Number of rows in the grid
    int C = G[0].size();       // Number of columns in the grid
    int r = P.size();          // Number of rows in the pattern
    int c = P[0].size();       // Number of columns in the pattern

    // Traverse through all potential starting positions in the grid
    for (int i = 0; i <= R - r; i++) {
        for (int j = 0; j <= C - c; j++) {
            bool found = true;

            // Check if the pattern matches the grid starting at (i, j)
            for (int pi = 0; pi < r; pi++) {
                for (int pj = 0; pj < c; pj++) {
                    if (G[i + pi][j + pj] != P[pi][pj]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }

            if (found) return "YES";  // Pattern found
        }
    }
    return "NO";  // Pattern not found
}

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        int R, C, r, c;

        // Input for grid
        cin >> R >> C;
        vector<string> G(R);
        for (int i = 0; i < R; i++) {
            cin >> G[i];
        }

        // Input for pattern
        cin >> r >> c;
        vector<string> P(r);
        for (int i = 0; i < r; i++) {
            cin >> P[i];
        }

        // Check if the pattern exists in the grid
        cout << gridSearch(G, P) << endl;
    }

    return 0;
}
