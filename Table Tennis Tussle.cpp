#include<bits/stdc++.h>
using namespace std;

int findMaxTeamSize(unordered_map<int, vector<int>> &graph) {
    unordered_map<int, int> color;
    int maxTeamSize = 0;

    for (const auto &entry : graph) {
        int node = entry.first;
        if (color.find(node) != color.end()) continue;

        int countA = 0, countB = 0;
        queue<int> q;
        q.push(node);
        color[node] = 0;
        countA++;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color.find(v) == color.end()) {
                    color[v] = 1 - color[u];
                    if (color[v] == 0) countA++;
                    else countB++;
                    q.push(v);
                }
            }
        }
        maxTeamSize += max(countA, countB);
    }
    return maxTeamSize;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << "Tournament " << t << ": " << findMaxTeamSize(graph) << endl;
    }
    return 0;
}

