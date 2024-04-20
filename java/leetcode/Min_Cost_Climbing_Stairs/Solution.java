package leetcode.Min_Cost_Climbing_Stairs;

class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] cost = {1,100,1,1,1,100,1,1,100,1};
        solution.minCostClimbingStairs(cost);
    }

    public int minCostClimbingStairs(int[] cost) {
        for (int i = cost.length-3; i >= 0; i--) {
            cost[i] += Math.min(cost[i+1], cost[i+2]);
        }
        return Math.min(cost[0], cost[1]);
    }
}