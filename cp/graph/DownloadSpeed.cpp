#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::min;

bool bfs(vector<vector<int>>& graph, vector<vector<long long>>& edges, vector<int>& parent, int source, int sink) {
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto son : graph[node]) {
            long long w = edges[node][son];
            if (w > 0 && parent[son] == -1) {
                parent[son] = node;
                q.push(son);
            }
        }
    }
    return parent[sink] != -1;
}

long long edmondsKarp(vector<vector<int>>& graph, vector<vector<long long>>& edges, int source, int sink) {
	int n = graph.size();
	vector<int> parent(n, -1);
	long long flow = 0;

	while (bfs(graph, edges, parent, source, sink)) {

		long long curr_flow = LLONG_MAX;
		for (int node = sink; node != sink; node = parent[node]) {
            int u = parent[node];
			curr_flow = min(curr_flow, edges[u][node]);
		}

		for (int node = sink; node != sink; node = parent[node]) {
            int u = parent[node];
			edges[u][node] -= curr_flow;
			edges[node][u] += curr_flow;
		}
		flow += curr_flow;
		fill(parent.begin(), parent.end(), -1);
	}

	return flow;
}

int main() {
	int n, m, a, b, c;
	std::cin >> n >> m;

	vector<vector<long long>> edges(n, vector<long long>(n, 0));
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b >> c;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		edges[a][b] += c;
	}

	std::cout << edmondsKarp(graph, edges, 0, n - 1) << std::endl;
}