#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited , int &component_size) {
    visited.insert(node);
    component_size++;
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited ,component_size);
        }
    }
}

vector<int>componentsInGraph(vector<vector<int>>bg)
{
    int n=bg.size();
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    for(int i=0;i<bg.size();i++){
        int u=bg[i][0];
        int v=bg[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>component_sizes;

    for (const auto& node_entry : graph) {
        int node = node_entry.first;
        if (visited.find(node) == visited.end()) {
            int component_size=0;
            dfs(node, graph, visited , component_size);
            if (component_size >= 2) {
                component_sizes.push_back(component_size);
            }
        }
    }
    if (component_sizes.empty()) {
        return {0, 0};  // No valid components
    }

    // Find the minimum and maximum component sizes
    int smallest = *min_element(component_sizes.begin(), component_sizes.end());
    int largest = *max_element(component_sizes.begin(), component_sizes.end());

    return {smallest, largest};
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>bg(n,vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>bg[i][0]>>bg[i][1];
    }

    vector<int>result=componentsInGraph(bg);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}

/**

5
1 6
2 7
3 8
4 9
2 6

*/
