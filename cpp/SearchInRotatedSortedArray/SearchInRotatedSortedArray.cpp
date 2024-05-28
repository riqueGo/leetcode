#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l<=r)
        {
            m = l + ((r-l)/2);

            if(nums[m] == target)
                return m;
            
            if(nums[m] >= nums[l])
            {
                if(target < nums[m] && target >= nums[l])
                    r = m-1;
                else
                    l = m+1;
            }
            else
            {
                if(target <= nums[r] && target > nums[m])
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return -1;
    }
};

/*
[l....m....r]
*/

int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    Solution solution;
    std::cout << solution.search(nums, 4);
}