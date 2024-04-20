#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num) > 0) return true; // Duplicate found
            seen.insert(num);
        }
        
        return false; // No duplicates found
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 1}; // Example input

    Solution solution;
    bool result = solution.containsDuplicate(nums);

    if (result) {
        std::cout << "Duplicate elements found." << std::endl;
    } else {
        std::cout << "No duplicate elements found." << std::endl;
    }

    return 0;
}
