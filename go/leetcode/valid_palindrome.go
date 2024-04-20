package leetcode

import "unicode"

func IsPalindrome(s string) bool {
	word := []rune{}

	for _, char := range s {
		if unicode.IsLetter(char) || unicode.IsDigit(char) {
			word = append(word, unicode.ToLower(char))
		}
	}

	l := 0
	r := len(word) - 1

	for l < r {
		if word[l] != word[r] {
			return false
		}
		l++
		r--
	}

	return true
}
