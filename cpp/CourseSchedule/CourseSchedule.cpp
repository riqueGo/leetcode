#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<unordered_map>

using std::vector;
using std::stack;
using std::unordered_set;
using std::unordered_map;
using std::array;

class Solution {
    private:
        unordered_map<int, vector<int>> graph;

        unordered_map<int, vector<int>> createGraph(vector<vector<int>>& prerequisites)
        {
            unordered_map<int, vector<int>> graph;

            for(vector<int> edge : prerequisites)
            {
                if (!graph.count(edge.at(1)))
                    graph[edge.at(1)] = {edge.at(0)};
                else
                    graph[edge.at(1)].push_back(edge.at(0));
            }
            return graph;
        }

        bool hasCycle(int v, vector<int>& visitedNodes, vector<int>& stack)
        {
            if (!visitedNodes[v])
            {
                visitedNodes[v] = 1;
                stack[v] = 1;

                for (int prerequisite : graph[v])
                {
                    if((!visitedNodes[prerequisite] && hasCycle(prerequisite, visitedNodes, stack)) || stack[prerequisite])
                        return true;
                }
            }

            stack[v] = 0;
            return false;
        }

    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
        {
            graph = createGraph(prerequisites);
            vector<int> visitedNodes(numCourses+1);
            vector<int> stack(numCourses+1);

            for (int i = 0; i <= numCourses; i++)
            {
                if (!visitedNodes[i] && hasCycle(i, visitedNodes, stack))
                    return false;
            }
            return true;
        }
};

int main()
{
    vector<vector<int>> prerequisites = {
        {1,4},
        {2,4},
        {3,1},
        {3,2}
    };

    Solution solution;
    solution.canFinish(4, prerequisites);
}