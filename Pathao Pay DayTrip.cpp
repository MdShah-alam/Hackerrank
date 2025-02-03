#include <iostream>
#include <vector>
using namespace std;

int minCarsRequired(vector<int>& groups) {
    vector<int> count(5, 0);

    for (int size : groups) {
        count[size]++;
    }

    int cars = count[4];

    cars += count[3];
    if (count[1] >= count[3]) {
        count[1] -= count[3];
    } else {
        count[1] = 0;
    }

    cars += count[2] / 2;
    if (count[2] % 2) {
        cars++;
        count[1] = max(0, count[1] - 2);
    }

    cars += (count[1] + 3) / 4;
    return cars;
}

int main() {
    int g;
    while (cin >> g) {
        vector<int> groups(g);
        for (int i = 0; i < g; ++i) {
            cin >> groups[i];
        }
        cout << minCarsRequired(groups) << endl;
    }
    return 0;
}

