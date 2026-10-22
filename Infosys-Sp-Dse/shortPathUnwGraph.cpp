// # Shortest Path in Unweighted Graph

// ## Problem

// Given an unweighted graph with `n` nodes and `m` edges, find the shortest distance from source node `0` to all other nodes.

// ## Example

// **Input**
// ```text
// 5 5
// 0 1
// 1 2
// 0 3
// 3 4
// 2 4
// ```

// **Output**
// ```text
// 0 1 2 1 2
// ```


// Code :- 



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    // Read edges (undirected graph)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, -1);
    queue<int> q;

    // Start BFS from node 0
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Print distances from node 0
    for (int i = 0; i < n; i++) {
        cout << dist[i];

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << '\n';
    return 0;
}
