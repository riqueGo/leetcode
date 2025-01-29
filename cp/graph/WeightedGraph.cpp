#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include <stack>
#include<algorithm>

using std::vector;
using std::pair;
using std::priority_queue;

typedef pair<int,int> Edge; //node, distance

class WeightedGraph {
    private:
    vector<vector<Edge>> graph;
    vector<int> previous;
    vector<int> distance;
    int start;

    public:
    WeightedGraph(vector<vector<Edge>>& graph) {
        this->graph = graph;
        this->previous = vector<int>(graph.size(), -1); 
        this->distance = vector<int>(graph.size(), INT_MAX); 
    }

    pair<vector<int>, vector<int>> dijkstra(int start) {
        this->start = start;
        priority_queue<Edge, vector<Edge>, std::greater<Edge>> pq;

        distance[start] = 0;
        pq.push({start, 0});

        while(!pq.empty()) {
            auto [currNode, currDist] = pq.top();
            pq.pop();

            if (currDist > distance[currNode]) continue;

            for(Edge edge : graph[currNode]) {
                int nextNode = edge.first;
                int weight = edge.second;
                int newDist = currDist + weight;

                if(newDist < distance[nextNode]) {
                    previous[nextNode] = currNode;
                    distance[nextNode] = newDist;
                    pq.push({nextNode, newDist});
                }
            }
        }
        return {distance, previous};
    }

    void printDistance() {
        std::cout << "Shortest distances from vertex " << start << " to others:" << std::endl;
        for (int i = 0; i < distance.size(); i++) {
            if (distance[i] == INT_MAX) {
                std::cout << "Vertex " << i << ": INF" << std::endl;
            } else {
                std::cout << "Vertex " << i << ": " << distance[i] << std::endl;
            }
        }
    }

    vector<int> getPath(int end) {
        vector<int> path;
        for (int v = end; v != -1; v = previous[v]) {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());

        if (path[0] != start) return {}; // No path found
        return path;
    }

    void printShortestPath(int end) {
        vector<int> path = this->getPath(end);
        if(path.empty()) {
            std::cout << "No path found from " << start << " to " << end << "." << std::endl;
            return;
        }

        std::cout << "Shortest path from " << start << " to " << end << ": ";
        for (int v : path) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    int n, m;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> n >> m;
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        graph[v].push_back({u, weight});
        graph[u].push_back({v, weight});  // Remove this for directed graph
    }

    WeightedGraph wg(graph);

    int start, end;
    std::cout << "Enter the starting vertex: ";
    std::cin >> start;
    std::cout << "Enter the destination vertex: ";
    std::cin >> end;

    auto [distances, previous] = wg.dijkstra(start);
    wg.printDistance();
    wg.printShortestPath(end);
}