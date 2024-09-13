#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int beautifulPairs(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> freqA, freqB;
    int n = A.size();

    // Count frequency of elements in A and B
    for (int i = 0; i < n; ++i) {
        freqA[A[i]]++;
        freqB[B[i]]++;
    }

    // Calculate the initial number of beautiful pairs
    int beautiful_pairs = 0;
    for (const auto& entry : freqA) {
        beautiful_pairs += min(entry.second, freqB[entry.first]);
    }

    // If we already have all possible pairs
    if (beautiful_pairs == n) {
        return n - 1;
    }

    // Otherwise, we can add one more pair
    return beautiful_pairs + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);

    // Input array A
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Input array B
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    // Output the maximum number of pairwise disjoint beautiful pairs
    cout << beautifulPairs(A, B) << endl;

    return 0;
}
