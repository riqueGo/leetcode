package leetcode.Jump_Game_2;

public class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2, 3, 1, 1, 4};
        int result = solution.jump(nums);

        System.out.println(result);
    }

    public int jump(int[] nums) {
        int level = 0;
        int left = 0, right = 0;

        while (right < nums.length-1) {
            int farthest = 0;
            for (int i = left; i < right+1; i++) {
                farthest = Math.max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            level++;
        }

        return level;
    }
}