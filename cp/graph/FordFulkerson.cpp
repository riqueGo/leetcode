#include <iostream>
#include <limits.h>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define V 6

// Função para encontrar um caminho aumentante usando DFS
bool dfs(vector<vector<int>>& rGraph, int u, int t, vector<int>& parent, vector<bool>& visited) {
    visited[u] = true;
    if (u == t) return true;
    
    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[u][v] > 0) {
            parent[v] = u;
            if (dfs(rGraph, v, t, parent, visited)) return true;
        }
    }
    return false;
}

// Implementação do algoritmo Ford-Fulkerson
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph; // Grafo residual
    vector<int> parent(V); // Armazena o caminho aumentante
    int max_flow = 0;

    while (true) {
        vector<bool> visited(V, false);
        if (!dfs(rGraph, s, t, parent, visited)) break;
        
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
    
    cout << "(fordFulkerson) O fluxo máximo é " << fordFulkerson(graph, 0, 5) << endl;
    return 0;
}
