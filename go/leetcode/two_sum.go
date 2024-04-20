package leetcode

func TwoSum(nums []int, target int) []int {
	numsMap := make(map[int]int)

	var temp int
	for i := 0; i < len(nums); i++ {
		temp = target - nums[i]
		if value, exists := numsMap[temp]; exists {
			return []int{value, i}
		}

		numsMap[nums[i]] = i
	}

	return []int{}
}
