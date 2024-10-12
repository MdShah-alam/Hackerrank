#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to determine if we can convert string a to string b
string abbreviation(string a, string b) {
    int n = a.length();
    int m = b.length();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;

    for (int i = 1; i <= n; i++) {
        if (islower(a[i - 1])) {
            dp[i][0] = dp[i - 1][0];  // We can delete the lowercase letter
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (toupper(a[i - 1]) == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (islower(a[i - 1])) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
        }
    }

    return dp[n][m] ? "YES" : "NO";
}

int main() {
    int q;  // Number of queries
    cin >> q;

    while (q--) {
        string a, b;
        cin >> a >> b;
        cout << abbreviation(a, b) << endl;
    }

    return 0;
}
