#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, count);
        }
    }
}

long long journeyToMoon(int n, vector<vector<int>>& astronaut) {

    vector<vector<int>> adj(n);
    for (vector<int>v : astronaut) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }

    vector<bool> visited(n, false);
    vector<int> country_sizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, adj, visited, count);
            country_sizes.push_back(count);
        }
    }
    long long total_pairs = (long long)n * (n - 1) / 2; // Total possible pairs
//    long long same_country_pairs = 0;

    for (int size : country_sizes) {
        total_pairs -= (long long)size * (size - 1) / 2; // Pairs within the same country
    }
//    cout<<total_pairs<<" "<<same_country_pairs<<endl;
    return total_pairs;
}

int main()
{
    int n,p;
    cin>>n>>p;
    vector<vector<int>>v;
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<journeyToMoon(n,v)<<endl;
    return 0;
}
/**

100000 2
1 2
3 4

*/
