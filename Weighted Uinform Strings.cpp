#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// Function to determine the weights of uniform substrings in string s
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    unordered_set<int> weights; // Store all possible weights of uniform substrings
    char prevChar = ' ';        // To keep track of previous character
    int currentWeight = 0;      // To store the current weight

    // Iterate through the string
    for (char c : s) {
        int weight = c - 'a' + 1; // Calculate weight of current character

        // If the current character is the same as the previous one, update current weight
        if (c == prevChar) {
            currentWeight += weight;
        } else {
            currentWeight = weight; // Start a new uniform substring
        }

        // Add the current weight to the set
        weights.insert(currentWeight);
        prevChar = c; // Update previous character
    }

    // Answer each query
    vector<string> result;
    for (int q : queries) {
        if (weights.find(q) != weights.end()) {
            result.push_back("Yes");
        } else {
            result.push_back("No");
        }
    }

    return result;
}

int main() {
    // Input the string and number of queries
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<int> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    // Call the function and get the result
    vector<string> result = weightedUniformStrings(s, queries);

    // Output the result
    for (const string& res : result) {
        cout << res << endl;
    }

    return 0;
}
