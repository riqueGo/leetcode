package leetcode.Container_With_Most_Water;

public class Solution {

    public int maxArea(int[] height) {
        int leftPointer = 0,
            rightPointer = height.length - 1,
            maxArea = 0;
        
        while (leftPointer < rightPointer) {
            int tempArea = areaCalculate(height[leftPointer], height[rightPointer], rightPointer - leftPointer);
            maxArea = Math.max(maxArea, tempArea);

            if (height[leftPointer] > height[rightPointer]) {
                rightPointer--;
            } else {
                leftPointer++;
            }
        }

        return maxArea;
    }

    private int areaCalculate(int heightA, int heightB, int length) {
        int minHeight = Math.min(heightA, heightB);
        return minHeight*length;
    }
}
