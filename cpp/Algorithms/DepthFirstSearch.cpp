#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Graph {
private:
    int vertex;
    vector<int>* graph;
    int* visitedVertices;
    stack<int> s;

    void initVisitedVertices(){
        visitedVertices = new int[vertex];
        std::fill(visitedVertices, visitedVertices + vertex, 0);
    }

    void dfsWalk(int node, vector<int>& result) {
        visitedVertices[node] = 1;
        result.push_back(node);

        for(auto& v : graph[node]) {
            if(!visitedVertices[v]) {
                dfsWalk(v, result);
            }
        }
    }

public:
    Graph(int n) : vertex(n) {
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

    void addUndirectedEdge(int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> dfsIterative(int n) {
        initVisitedVertices();
        vector<int> result;

        visitedVertices[n] = 1;
        s.push(n);

        while(!s.empty()) {
            int curr = s.top();
            s.pop();

            result.push_back(curr);
            for(auto& v : graph[curr]) {
                if(visitedVertices[v]) continue;

                visitedVertices[v] = 1;
                s.push(v);
            }
        }

        delete[] visitedVertices;
        return result;
    }

    vector<int> dfsRecursive(int node) {
        initVisitedVertices();
        vector<int> dfs;
        dfsWalk(node, dfs);
        delete[] visitedVertices;
        return dfs;
    }
};


int main() {
    Graph graph(10);

    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 6);
    graph.addUndirectedEdge(1, 2);
    graph.addUndirectedEdge(1, 5);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(2, 4);
    graph.addUndirectedEdge(6, 7);
    graph.addUndirectedEdge(6, 9);
    graph.addUndirectedEdge(7, 8);

    graph.printGraph();

    vector<int> result = graph.dfsIterative(0);
    for(int v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}