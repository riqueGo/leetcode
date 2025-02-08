#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::min;

bool bfs(
	vector<vector<long long>>& graph,
	vector<int>& levels,
	const int source,
	const int sink,
	const int n
) {
	fill(levels.begin(), levels.end(), -1);
	queue<int> q;
	q.push(source);
	levels[source] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if(levels[i] < 0 && graph[node][i] > 0) {
				levels[i] = levels[node] + 1;
				q.push(i);
			}
		}
	}

	return levels[sink] >= 0;
}

long long dfs(
	vector<vector<long long>>& graph,
	vector<int>& levels,
	vector<int>& path,
	const int source,
	const int sink,
	const int n,
	const long long flow
) {
	if(source == sink) {
		return flow;
	}

	for(; path[source] < n; path[source]++) {
		int e = path[source];
		if (levels[e] != levels[source] + 1 || graph[source][e] <= 0) {
			continue;
		}

		long long minFlow = min(flow, graph[source][e]);
		if(long long pushedFlow = dfs(graph, levels, path, e, sink, n, minFlow)) {
			graph[source][e] -= pushedFlow;
			graph[e][source] += pushedFlow;
			return pushedFlow;
		}
	}

	return 0;
}


int main() {
	int n, m, a, b, c;
	std::cin >> n >> m;

	vector<vector<long long>> graph(n, vector<long long>(n, 0));
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b >> c;
		--a;
		--b;
		graph[a][b] += c;
	}

	vector<int> levels(n);
	long long maxFlow = 0;

	while (bfs(graph, levels, 0, n-1, n)) {
		vector<int> path(n, 0);
		while (long long flow = dfs(graph, levels, path, 0, n-1, n, LLONG_MAX)) {
			maxFlow += flow;
		}
	}

	std::cout << maxFlow << std::endl;
}