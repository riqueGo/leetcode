#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::string;
using std::sort;

class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            unordered_set<int> alreadyCounted;
            int l, r, tempSum;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size()-2; i++)
            {
                if(alreadyCounted.count(nums[i])) continue;

                alreadyCounted.insert(nums[i]);

                l = i+1;
                r = nums.size() - 1;
                unordered_set<int> alreadyCountedL;

                while (l < r)
                {
                    tempSum = nums[i] + nums[l] + nums[r];
                    if (tempSum > 0)
                        r--;
                    else if(tempSum < 0)
                        l++;
                    else
                    {
                        if (!alreadyCountedL.count(l))
                        {
                            result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                            alreadyCountedL.insert(l);
                        }
                        l++;
                    }
                }
            }
            return result;
        }
};

int main() {
    Solution solution;
    solution.threeSum(vector<int>{-1,0,1,2,-1,-4});
}