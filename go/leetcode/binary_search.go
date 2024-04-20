package leetcode

func search(nums []int, target int) int {
	low := 0
	righ := len(nums) - 1

	for low <= righ {
		mid := int(low + ((righ - low) / 2))

		if nums[mid] < target {
			low = mid + 1
		} else if nums[mid] > target {
			righ = mid - 1
		} else {
			return mid
		}
	}

	return -1

}
