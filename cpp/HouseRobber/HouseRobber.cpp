#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0, temp;
        for(int i = 0; i < nums.size(); i++)
        {
            temp = curr;
            curr = max(curr, prev+nums[i]);
            prev = temp;
        }
        return curr;
    }
};