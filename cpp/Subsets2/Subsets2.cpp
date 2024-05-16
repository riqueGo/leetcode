#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::sort;

class Solution {

private:
    vector<vector<int>> result;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currResult;
        combinations(nums, currResult, 0);
        return result;
    }

    void combinations(vector<int>& nums, vector<int>& currResult, int index)
    {
        if(index >= nums.size())
        {
            result.push_back(vector<int>(currResult));
            return;
        }

        int prevValue = nums[index];
        currResult.push_back(prevValue);
        combinations(nums, currResult, ++index);
        currResult.pop_back();

        while(index < nums.size() && nums[index] == prevValue)
            index++;
        
        combinations(nums, currResult, index);
    }
};

int main()
{
    vector<int> nums = {1,2,2};
    Solution s;
    s.subsetsWithDup(nums);
}