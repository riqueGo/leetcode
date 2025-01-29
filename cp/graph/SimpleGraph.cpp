#include <iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

class SimpleGraph {
    private:
    vector<vector<int>> graph;

    public:
    SimpleGraph(int nodes) {
        graph = vector<vector<int>>(nodes);
    }

    SimpleGraph(vector<vector<int>>& graph) {
        this->graph = graph;
    }

    void addEdge(int fromNode, int toNode) {
        graph[fromNode].push_back(toNode);
    }

    void dfs(int node, vector<bool>& visited) {
        if (visited[node]) return;

        visited[node] = true;
        std::cout << node << std::endl;

        for (int toVisitNode : graph[node]) {
            dfs(toVisitNode, visited);
        }
    }

    void bfs(int node) {
        queue<int> q;
        q.push(node);

        vector<bool> visited (graph.size(), false);

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();

            visited[currNode] = true;
            std::cout << currNode << std::endl;

            for(int toVisitNode : graph[currNode]) {
                if(!visited[toVisitNode]) {
                    q.push(toVisitNode);
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> graph(6);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1, 5};
    graph[4] = {1};
    graph[5] = {3};

    SimpleGraph sg(graph);

    vector<bool> visited(6, false);
    std::cout << "DFS" << std::endl;
    sg.dfs(0, visited);
    std::cout << std::endl;
    std::cout << "BFS" << std::endl;
    sg.bfs(0);
}