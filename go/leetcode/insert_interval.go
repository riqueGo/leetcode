package leetcode

func insert(intervals [][]int, newInterval []int) [][]int {
	if newInterval[1] < intervals[0][0] {
		return append([][]int{newInterval}, intervals...)
	}

	if newInterval[0] > intervals[len(intervals)-1][1] {
		return append(intervals, newInterval)
	}

	low := 0
	high := len(intervals) - 1
	var mid int

	for low <= high {
		mid = low + ((high - low) / 2)

		if newInterval[0] > intervals[mid][0] {
			high = mid - 1
		} else if newInterval[0] < intervals[mid][0] {
			low = mid + 1
		} else {
			break
		}
	}
}
