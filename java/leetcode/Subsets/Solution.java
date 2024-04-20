package leetcode.Subsets;

import java.util.LinkedList;
import java.util.List;

class Solution {
    private List<List<Integer>> result;

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        Solution solution = new Solution();
        solution.subsets(nums);
    }

    public Solution() {
        result = new LinkedList<>();
    }

    public List<List<Integer>> subsets(int[] nums) {
        sub(nums, 0, new LinkedList<>());
        return result;
    }

    private void sub(int[] nums, int i, LinkedList<Integer> subList){
        LinkedList<Integer> newSubList = new LinkedList<>(subList);
        if (i >= nums.length) {
            result.add(newSubList);
            return;
        }

        newSubList.push(nums[i]);
        sub(nums, i+1, newSubList);
        newSubList.pop();
        sub(nums, i+1, newSubList);
    }
}