#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int removableEdges = 0;

// DFS function to count the nodes in each subtree
int dfs(int node) {
    visited[node] = true;
    int nodeCount = 1;  // Count the current node

    // Traverse all adjacent nodes
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            int subtreeNodeCount = dfs(neighbor);

            // If subtree has even number of nodes, we can remove this edge
            if (subtreeNodeCount % 2 == 0) {
                removableEdges++;
            } else {
                nodeCount += subtreeNodeCount;  // Add to the current subtree
                cout<<nodeCount<<" ";
            }
        }
    }
    return nodeCount;
}

int evenForest(int t_nodes, int t_edges, vector<int>& t_from, vector<int>& t_to) {
    tree.resize(t_nodes + 1);
    visited.resize(t_nodes + 1, false);

    for (int i = 0; i < t_edges; i++) {
        tree[t_from[i]].push_back(t_to[i]);
        tree[t_to[i]].push_back(t_from[i]);
    }
    dfs(1);
    cout<<endl;
    return removableEdges;
}

int main() {
    int t_nodes, t_edges;
    cin >> t_nodes >> t_edges;

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        cin >> t_from[i] >> t_to[i];
    }
    cout << evenForest(t_nodes, t_edges, t_from, t_to) << endl;

    return 0;
}

