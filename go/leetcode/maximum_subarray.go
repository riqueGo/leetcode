package leetcode

import "math"

func maxSubArray(nums []int) int {
	temp := 0
	maximum := math.MinInt

	for _, num := range nums {
		temp += num
		maximum = max(temp, maximum)

		if temp < 0 {
			temp = 0
		}
	}

	return maximum
}
