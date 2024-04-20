package leetcode

func climbStairs(n int) int {
	x, y, temp := 1, 1, 0

	for i := 1; i < n; i++ {
		temp = y
		y += x
		x = temp
	}

	return y
}
