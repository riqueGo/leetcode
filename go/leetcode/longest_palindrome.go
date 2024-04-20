package leetcode

func longestPalindrome(s string) int {
	lettersByFrequency := make(map[rune]int)

	for _, letter := range s {
		lettersByFrequency[letter]++
	}

	oddCount := 0
	result := 0

	for _, frenquency := range lettersByFrequency {
		if frenquency%2 != 0 {
			oddCount++
		}
		result += frenquency
	}

	if oddCount > 1 {
		return result - oddCount + 1
	}

	return result
}
