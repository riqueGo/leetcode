#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class Solution {
private:
    int result = 0 ;

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            dfs(nums,visited,i);
        }
        return result;
    }

    int dfs(vector<int>& nums, vector<int>& visited, int startIndex)
    {
        if(visited[startIndex])
            return visited[startIndex];
        
        visited[startIndex] = 1;
        int longest = 0;
        for(int i = startIndex+1; i < nums.size(); i++)
        {
            if(nums[i] > nums[startIndex])
                longest = max(longest, dfs(nums, visited, i));
        }

        visited[startIndex] += longest;
        result = max(result, visited[startIndex]);
        return visited[startIndex];
    }
};
