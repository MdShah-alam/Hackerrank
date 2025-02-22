#include <bits/stdc++.h>
using namespace std;

// Function to check if a string contains only alternating characters
bool isAlternating(const string &s, char first, char second) {
    char prev = '\0';
    for (char c : s) {
        if (c != first && c != second) continue;
        if (c == prev) return false;  // Consecutive same characters
        prev = c;
    }
    return true;
}

// Function to find the longest alternating string possible
int alternate(string s) {
    unordered_set<char> unique_chars(s.begin(), s.end());
    vector<char> chars(unique_chars.begin(), unique_chars.end());

    int max_length = 0;

    // Try every pair of characters
    for (size_t i = 0; i < chars.size(); ++i) {
        for (size_t j = i + 1; j < chars.size(); ++j) {
            char first = chars[i], second = chars[j];

            // Filter the string to only keep the chosen pair
            string filtered = "";
            for (char c : s) {
                if (c == first || c == second) {
                    filtered += c;
                }
            }

            // Check if the filtered string is alternating
            if (isAlternating(filtered, first, second)) {
                max_length = max(max_length, (int)filtered.size());
            }
        }
    }

    return max_length;
}

// Main function
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << alternate(s) << endl;
    return 0;
}
