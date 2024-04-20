#include <iostream>
#include <queue>
#include <vector>
#include <array>

using std::queue;
using std::vector;
using std::array;

class Graph {
private:
    int vertex;
    vector<int>* graph;
    int* visitedVertice;
    queue<int> q;

    void initVisitedVertices() {
        visitedVertice = new int[vertex];
        std::fill(visitedVertice, visitedVertice + vertex, 0);
    }

public:
    Graph(int n) {
        vertex = n;
        graph = new vector<int>[n];
    }

    ~Graph() {
        delete[] graph;
    }

    void printGraph() const {
        for(int i = 0; i < vertex; i++) {
            std::cout << i << " --> ";
            for(auto& v : graph[i]){
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

    void addEdgeUndirected(int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> bfs(int node) {
        initVisitedVertices();
        visitedVertice[node] = 1;
        q.push(node);

        vector<int> result;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            result.push_back(currNode);

            for(auto& v : graph[currNode]){
                if(visitedVertice[v]) continue;

                visitedVertice[v] = 1;
                q.push(v);
            }
        }

        delete[] visitedVertice;
        return result;
    }
};

int main() {
    Graph graph(10);

    graph.addEdgeUndirected(0, 1);
    graph.addEdgeUndirected(0, 6);
    graph.addEdgeUndirected(1, 2);
    graph.addEdgeUndirected(1, 5);
    graph.addEdgeUndirected(2, 3);
    graph.addEdgeUndirected(2, 4);
    graph.addEdgeUndirected(6, 7);
    graph.addEdgeUndirected(6, 9);
    graph.addEdgeUndirected(7, 8);


    graph.printGraph();

    vector<int> bfs = graph.bfs(0);
    std::cout << "bfs: ";
    for (int i = 0; i < bfs.size(); i++) {
        std::cout << bfs[i] << " ";
    }
}