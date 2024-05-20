#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost[0], y = cost[1], temp;

        for(int i = 2; i < cost.size(); i++)
        {
            temp = y;
            y = min(x,y) + cost[i];
            x = temp;
        }
        return min(x,y);
    }
};