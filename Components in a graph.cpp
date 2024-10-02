#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Helper function for DFS traversal
void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int& component_size) {
    visited.insert(node);  // Mark the node as visited
    component_size++;  // Increment the component size

    // Traverse all neighbors of the current node
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited, component_size);
        }
    }
}

// Main function to find smallest and largest connected components
vector<int>componentsInGraph(vector<vector<int>>& bg) {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    // Build the adjacency list representation of the graph
    for (const auto& edge : bg) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> component_sizes;

    // Iterate over all nodes in the graph
    for (const auto& node_entry : graph) {
        int node = node_entry.first;
        if (visited.find(node) == visited.end()) {
            int component_size = 0;
            // Perform DFS to calculate the size of the connected component
            dfs(node, graph, visited, component_size);

            // Only consider components with 2 or more nodes
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

int main() {
    int n;
    cin >> n;
    vector<vector<int>> bg(n, vector<int>(2));

    // Input edges
    for (int i = 0; i < n; ++i) {
        cin >> bg[i][0] >> bg[i][1];
    }

    // Get the result
    vector<int> result = componentsInGraph(bg);

    // Output the result
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
