#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::swap;

class Solution {
private:
    vector<vector<int>> result;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        combinations(nums, 0);
        return result;
    }

    void combinations(vector<int>& nums, int currIndex)
    {
        if(currIndex == nums.size()-1)
        {
            result.push_back(nums);
            return;
        }

        for(int i = currIndex; i < nums.size(); i++)
        {
            swap(nums[i], nums[currIndex]);
            combinations(nums, currIndex+1);
            swap(nums[i], nums[currIndex]);
        }
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    s.permute(nums);
}