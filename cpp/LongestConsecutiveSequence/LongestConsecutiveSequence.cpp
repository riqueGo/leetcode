#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::set;

class Solution {

    public:
        int longestConsecutive(vector<int>& nums){
            if(nums.empty()) return 0;
            if(nums.size() == 1) return 1;

            std::sort(nums.begin(), nums.end());
            int result = 1, tempResult = 1;

            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] - nums[i - 1] == 1){
                    tempResult++;
                    continue;
                } else if (nums[i] - nums[i - 1] == 0){
                    continue;
                } 

                result = std::max(tempResult, result);
                tempResult = 1;
            }

            result = std::max(tempResult, result);
            return result;
        }

        int longestConsecutiveUnorderedSet(vector<int>& nums) {
            unordered_set<int>s(nums.begin(), nums.end());
            int longest = 0;
            for(auto &n: s){
                //if this is the start of the sequence
                if(!s.count(n - 1)){
                    int length = 1; 
                    while(s.count(n + length))
                        ++length;
                    longest = std::max(longest, length);
                } 

            }
            return longest;
        }
};

int main(){
    // vector<int> nums = {100,4,200,1,3,2};
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    // vector<int> nums = {0};
    // vector<int> nums = {};
    vector<int> nums = {0,1,1,2};

    Solution solution;
    std::cout << solution.longestConsecutiveUnorderedSet(nums) << std::endl;
}

