#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);  // Stores predecessors
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i < V; i++) {
            for (const auto &edge : edges) {
                if (dist[edge.src] != numeric_limits<int>::max() &&
                    dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                    parent[edge.dest] = edge.src; // Store predecessor
                }
            }
        }

        // Check for negative weight cycles
        for (const auto &edge : edges) {
            if (dist[edge.src] != numeric_limits<int>::max() &&
                dist[edge.src] + edge.weight < dist[edge.dest]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }

        // Print shortest distances and paths
        cout << "Vertex Distance from Source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == numeric_limits<int>::max()) {
                cout << i << " -> INF\n";
            } else {
                cout << i << " -> " << dist[i] << " | Path: ";
                printPath(parent, i);
                cout << endl;
            }
        }
    }

    void printPath(vector<int> &parent, int v) {
        if (parent[v] == -1) {
            cout << v;
            return;
        }
        printPath(parent, parent[v]);
        cout << " -> " << v;
    }
};

int main() {
    int V = 5;
    int E = 8;
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}
