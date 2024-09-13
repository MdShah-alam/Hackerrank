#include<bits/stdc++.h>
using namespace std;

string organizingContainers(vector<vector<int>>& container) {
    int n = container.size();
    // Calculate total balls in each container
    vector<int> containerSums(n, 0);
    vector<int> typeSums(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            containerSums[i] += container[i][j];
            typeSums[j] += container[i][j];
        }
    }
    // Sort the total number of balls in each container and each type
    sort(containerSums.begin(), containerSums.end());
    sort(typeSums.begin(), typeSums.end());

    // Compare if both sorted sums are identical
    if (containerSums == typeSums) {
        return "Possible";
    } else {
        return "Impossible";
    }
}

int main() {
    int q;
    cin >> q;  // Number of queries

    while (q--) {
        int n;
        cin >> n;

        vector<vector<int>> container(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> container[i][j];
            }
        }

        cout << organizingContainers(container) << endl;
    }

    return 0;
}
