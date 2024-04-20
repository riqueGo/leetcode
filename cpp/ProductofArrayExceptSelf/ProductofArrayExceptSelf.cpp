#include <iostream>
#include <vector>

using std::vector;

class Solution {
    public:
        vector<int> productExceptSelfPreAndPost(vector<int>& nums){
            int n = nums.size();
            vector<int> prefix(n);
            vector<int> postfix(n);
            vector<int> result(n);

            prefix[0] = nums[0];
            for(int i = 1; i < n; i++){
                prefix[i] = prefix[i-1] * nums[i];
            }

            postfix[n-1] = nums[n-1];
            for(int i = n-2; i >= 0; i--){
                postfix[i] = postfix[i+1] * nums[i];
            }

            result[0] = postfix[1];
            result[n-1] = prefix[n-2];

            for(int i = 1; i < n-1; i++){
                result[i] = prefix[i-1]*postfix[i+1];
            }
            return result;
        }

        vector<int> productExceptSelf(vector<int>& nums){
            int n = nums.size();
            vector<int> result(n,1);

            int product = 1;
            for(int i = 0; i < n; i++){
                result[i] = product;
                product *= nums[i];
            }

            product = 1;
            for(int i = n-1; i >= 0; i--){
                result[i] *= product;
                product *= nums[i];
            }

            return result;
        }
};

int main() {
    vector<int> nums = {1,2,3,4};
    
    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    for(int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}