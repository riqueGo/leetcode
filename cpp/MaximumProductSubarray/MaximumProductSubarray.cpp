#include<vector>
#include<algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSub = -11, currMax = 1, currMin = 1, temp;

        for(int i = 0; i < nums.size(); i++)
        {
            temp = currMax;
            currMax = max(max(nums[i]*currMax, nums[i]*currMin), nums[i]);
            currMin = min(min(nums[i]*temp, nums[i]*currMin), nums[i]);
            maxSub = max(maxSub, currMax);
        }
        return maxSub;
    }
};
