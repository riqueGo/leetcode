#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::sort;
using std::min;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int dp[amount+1];
        dp[0] = 0;

        for(int i = 1; i < amount+1; i++)
        {
            dp[i] = INT_MAX;
            for(int j = 0; j < coins.size() && i >= coins[j]; j++)
            {
                if(dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1,2,5};
    int result = solution.coinChange(coins, 6);
    std::cout << result;
}