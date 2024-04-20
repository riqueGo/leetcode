package leetcode

func canConstruct(ransomNote string, magazine string) bool {
	var letters [26]int

	for _, letter := range magazine {
		letters[letter-'a']++
	}

	for _, letter := range ransomNote {
		letters[letter-'a']--

		if letters[letter-'a'] < 0 {
			return false
		}
	}

	return true
}
