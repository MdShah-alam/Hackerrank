#include<bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int, int>>> adj(n + 1);  // Correct graph representation
    // Building the adjacency list
    for (vector<int> v : edges) {
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }

    vector<int> visited(n + 1, 0);  // To track visited nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});  // Push {weight, node}

    int sum = 0;
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int wt = it.first;
        int node = it.second;

        if (visited[node]) continue;

        visited[node] = 1;
        sum += wt;

        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[adjNode]) {
                q.push({edgeWeight, adjNode});
            }
        }
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>k(3);
        k[0]=a;
        k[1]=b;
        k[2]=c;
        v.push_back(k);
    }
    int start;
    cin>>start;
    cout<<prims(n,v,start)<<endl;
    return 0;
}

/**

5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1

*/
