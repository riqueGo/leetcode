#include <iostream>
#include <limits.h>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define V 6


bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return false;
}

// Implementação do algoritmo Edmonds-Karp
int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph; // Grafo residual
    vector<int> parent(V); // Armazena o caminho aumentante
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    vector<vector<int>> graph = { {0, 16, 13, 0, 0, 0},
                                   {0, 0, 10, 12, 0, 0},
                                   {0, 4, 0, 0, 14, 0},
                                   {0, 0, 9, 0, 0, 20},
                                   {0, 0, 0, 7, 0, 4},
                                   {0, 0, 0, 0, 0, 0} };
    
    cout << "(edmondsKarp) O fluxo máximo é " << edmondsKarp(graph, 0, 5) << endl;
    return 0;
}
