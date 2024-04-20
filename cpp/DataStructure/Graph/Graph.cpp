#include <iostream>
#include <vector>

using std::vector;
using std::pair;

//Space O(n²)
void matrixUndirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

//Space O(n²)
void matrixDirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
    }
}

//Space O(n²)
void matrixUndirectedWeightedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
}

//Space O(n²)
void matrixDirectedWeightedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u][v] = wt;
    }
}

//Space O(2*E)
void listUndirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

//Space O(E)
void listDirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
}

//Space O(2*E)
void listUndirectedWeightedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back(pair(u, wt));
        adj[v].push_back(pair(u, wt));
    }
}

//Space O(2*E)
void listDirectedWeightedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back(pair(u, wt));
    }
}