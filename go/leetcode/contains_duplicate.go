package leetcode

func containsDuplicate(nums []int) bool {
	duplicateNums := make(map[int]bool)

	for _, num := range nums {
		if _, exists := duplicateNums[num]; exists {
			return true
		}
		duplicateNums[num] = true
	}

	return false
}
