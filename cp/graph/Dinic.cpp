#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define V 6 // Número de vértices no grafo

// Função para construir o nível do grafo usando BFS
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& level) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (level[v] < 0 && rGraph[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] >= 0;
}

// Função DFS para encontrar caminhos aumentantes
int dfs(vector<vector<int>>& rGraph, vector<int>& level, vector<int>& start, int u, int t, int flow) {
    if (u == t) return flow;
    
    for (int& v = start[u]; v < V; v++) {
        if (level[v] == level[u] + 1 && rGraph[u][v] > 0) {
            int min_flow = min(flow, rGraph[u][v]);
            int pushed = dfs(rGraph, level, start, v, t, min_flow);
            if (pushed > 0) {
                rGraph[u][v] -= pushed;
                rGraph[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

// Implementação do algoritmo de Dinic
int dinic(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph; // Grafo residual
    vector<int> level(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, level)) {
        vector<int> start(V, 0);
        while (int flow = dfs(rGraph, level, start, s, t, INT_MAX)) {
            max_flow += flow;
        }
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
    
    cout << "O fluxo máximo é " << dinic(graph, 0, 5) << endl;
    return 0;
}
