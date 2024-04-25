#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::priority_queue;

class Solution
{
    public:
        struct KClosestNode
        {
            vector<int> point;
            int distance;

            bool operator<(const KClosestNode& other) const
            {
                return distance > other.distance;
            }
        };

        int calculateDistance(vector<int> point)
        {
            return (point[0] * point[0]) + (point[1] * point[1]);
        }

        KClosestNode newKClosestNode(vector<int> point)
        {
            return KClosestNode{point, calculateDistance(point)};
        }

        vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
        {
            priority_queue<KClosestNode> heap;

            for(vector<int> point : points)
            {
                heap.push(newKClosestNode(point));
                if (heap.size() > k)
                {
                    heap.pop();
                }
            }

            vector<vector<int>> result;

            while (!heap.empty())
            {
                result.push_back(heap.top().point);
                heap.pop();
            }

            return result;
        }
};