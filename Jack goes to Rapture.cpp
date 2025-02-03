#include<bits/stdc++.h>
using namespace std;

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // Build the adjacency list
    vector<vector<pair<int, int>>> adj(g_nodes + 1);
    for (int i = 0; i < g_from.size(); ++i) {
        adj[g_from[i]].push_back({g_to[i], g_weight[i]});
        adj[g_to[i]].push_back({g_from[i], g_weight[i]});  // since it's undirected
    }

    vector<int> minFare(g_nodes + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from station 1
    pq.push({0, 1});
    minFare[1] = 0;

    while (!pq.empty()) {
        auto [currFare, node] = pq.top();
        pq.pop();

        // If we reach the last station, print the cost and return
        if (node == g_nodes) {
            cout << currFare << endl;
            return;
        }

        for (auto [neighbor, fare] : adj[node]) {
            int costToNeighbor = fare - currFare;
            costToNeighbor = max(costToNeighbor, 0);  // If negative, the cost is free

            if (currFare + costToNeighbor < minFare[neighbor]) {
                minFare[neighbor] = currFare + costToNeighbor;
                pq.push({minFare[neighbor], neighbor});
            }
        }
    }

    // If we can't reach the last station
    cout << "NO PATH EXISTS" << endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>g_from(n),g_to(n),g_weight(n);
    for(int i=0;i<m;i++){
        cin>>g_from[i]>>g_to[i]>>g_weight[i];
    }
    getCost(n,g_from,g_to,g_weight);
    cout<<endl;
    return 0;
}
/**

5 6
1 2 30
2 3 50
3 4 70
4 5 90
1 3 70
3 5 85

*/
