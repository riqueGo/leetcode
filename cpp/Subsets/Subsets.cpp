#include<iostream>
#include<vector>

using std::vector;


class Solution {

private:
    vector<vector<int>> result;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubSet;
        fillSubset(nums, currSubSet, 0);
        return result;
    }

    void fillSubset(vector<int>& nums, vector<int>& currSubSet, int index)
    {
        if(index == nums.size())
        {
            result.push_back(vector<int>(currSubSet));
            return;
        }

        currSubSet.push_back(nums[index]);
        fillSubset(nums, currSubSet, index+1);
        currSubSet.pop_back();
        fillSubset(nums, currSubSet, index+1);
    }

    vector<vector<int>> subsetsIterative(vector<int>& nums) {
        vector<vector<int>> result = {{}, {nums[0]}};

        for(int i = 1; i < nums.size(); i++)
        {
            int resultSize = result.size();
            for(int j = 0; j < resultSize; j++)
            {
                vector<int> newVec(result[j]);
                newVec.push_back(nums[i]);
                result.push_back(newVec);
            }
        }
        return result;
    }
};