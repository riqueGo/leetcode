package leetcode

func isBadVersion(version int) bool {
	return version == 4 //example
}

func firstBadVersion(n int) int {
	left := 1

	for left < n {
		mid := left + (n-left)/2
		if isBadVersion(mid) {
			n = mid
		} else {
			left = mid + 1
		}
	}

	return left
}
