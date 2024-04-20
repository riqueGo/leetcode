#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
    public:
        std::vector<int> twoSumWithTwoPointer(std::vector<int>& nums, int target) {
            std::vector<int> copy(nums);

            std::sort(copy.begin(), copy.end());

            int i = 0,j = copy.size() - 1, tempSum;

            while( i < copy.size() - 1 && j > 0 && i != j) {
                tempSum = copy[i] + copy[j];
                if(tempSum > target) j--;
                else if (tempSum < target) i++;
                else break;
            }
            int x = copy[i], y = copy[j];
            bool hasX = false, hasY = false;
            std::vector<int> result;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == x && !hasX) {
                    result.push_back(i);
                    hasX = true;
                } else if(nums[i] == y && !hasY) {
                    result.push_back(i);
                    hasY = true;
                }
                if(hasX && hasY){
                    break;
                }
            }
            return result;
        }

        std::vector<int> twoSumWithMap(std::vector<int>& nums, int target) {
            std::unordered_map<int,int> umap;
            std::vector<int> result;
            int tempSecondValue;
            for(int i = 0; i < nums.size(); i++){
                tempSecondValue = target - nums[i];
                if(umap.count(tempSecondValue) > 0){
                    result.push_back(umap.at(tempSecondValue));
                    result.push_back(i);
                    break;
                }

                umap[nums[i]] = i;
            }
            return result;
        }
};

int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    //solution = 0,1

    // std::vector<int> nums = {3,2,4};
    // int target = 6;
    //solution = 1,2    
    
    // std::vector<int> nums = {3,3};
    // int target = 6;
    // solution = 0,1

    Solution solution;
    std::vector<int> result = solution.twoSumWithMap(nums, target);

    for (int num : result) {
        std::cout << num << std::endl;
    }
}