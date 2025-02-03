#include<bits/stdc++.h>
using namespace std;

int n, totalLength;
vector<int>bamboo;
vector<bool>used;

bool dfs(int index, int currentLength, int targetLength, int count) {
    if (count == 0) return true;
    if (currentLength == targetLength) return dfs(0, 0, targetLength, count - 1);

    for (int i = index; i < n; ++i) {
        if (used[i] || currentLength + bamboo[i] > targetLength) continue;

        used[i] = true;
        if (dfs(i + 1, currentLength + bamboo[i], targetLength, count)) return true;
        used[i] = false;

        if (currentLength == 0) return false;
        while (i + 1 < n && bamboo[i] == bamboo[i + 1]) ++i;
    }
    return false;
}

int findOriginalLength() {
    sort(bamboo.rbegin(), bamboo.rend());

    for (int targetLength = bamboo[0]; targetLength <= totalLength; ++targetLength) {
        if (totalLength % targetLength == 0) {
            used.assign(n, false);
            if (dfs(0, 0, targetLength, totalLength / targetLength)) {
                return targetLength;
            }
        }
    }
    return totalLength;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;

        bamboo.resize(n);
        totalLength = 0;
        for (int i = 0; i < n; ++i) {
            cin >> bamboo[i];
            totalLength += bamboo[i];
        }

        cout << findOriginalLength() << endl;
    }
    return 0;
}
