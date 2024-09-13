#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Precompute prefix frequency arrays for each character 'a' to 'z'
vector<vector<int>> prefixFreq;

// Initialize the prefix frequency arrays
void initialize(string s) {
    int n = s.length();
    prefixFreq.assign(26, vector<int>(n + 1, 0));

    // Fill the prefix frequency array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            prefixFreq[j][i + 1] = prefixFreq[j][i];  // Copy previous counts
        }
        prefixFreq[s[i] - 'a'][i + 1]++;  // Increment the current character's count
    }
}

// Function to answer a query
int answerQuery(int l, int r) {
    // Adjust l and r for 0-based indexing
    l--; r--;

    // Count the number of characters with odd frequencies
    int oddCount = 0;
    for (int i = 0; i < 26; ++i) {
        int charFreq = prefixFreq[i][r + 1] - prefixFreq[i][l];
        if (charFreq % 2 != 0) oddCount++;
    }

    // Maximum length palindrome = all even frequencies + at most 1 odd frequency
    // Number of ways to choose which character will be the center (if oddCount > 0)
    int maxLengthPalindromes = max(1, oddCount);

    return maxLengthPalindromes % MOD;
}

int main() {
    string s;
    int q;

    // Input the string
    cin >> s;
    initialize(s);

    cin >> q;

    // Answer each query
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << answerQuery(l, r) << endl;
    }

    return 0;
}

