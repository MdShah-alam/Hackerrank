#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Function to process the operations and return the results of "3" queries
vector<int> getMax(const vector<string>& operations) {
    stack<int> mainStack;      // Main stack to store elements
    stack<int> maxStack;       // Helper stack to track the maximums
    vector<int> results;       // To store the results of "3" queries

    for (const string& operation : operations) {
        if (operation[0] == '1') {
            // Extract the number to push
            int x = stoi(operation.substr(2));
            mainStack.push(x);

            // If maxStack is empty or x is greater than or equal to the top of maxStack, push x into maxStack
            if (maxStack.empty() || x >= maxStack.top()) {
                maxStack.push(x);
            }
        }
        else if (operation[0] == '2') {
            // Pop the top element from the main stack
            int topElement = mainStack.top();
            mainStack.pop();

            // If the top of the maxStack is equal to the popped element, pop the maxStack
            if (!maxStack.empty() && maxStack.top() == topElement) {
                maxStack.pop();
            }
        }
        else if (operation[0] == '3') {
            // The current maximum element is the top of the maxStack
            if (!maxStack.empty()) {
                results.push_back(maxStack.top());
            }
        }
    }

    return results;
}

int main() {
    int n;
    cin >> n; // Number of queries
    vector<string> operations(n);

    // Read all operations
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, operations[i]);
    }

    // Get the results of the "3" operations
    vector<int> result = getMax(operations);

    // Output the results
    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}

/**

10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

*/
