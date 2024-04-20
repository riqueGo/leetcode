package leetcode

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	var letters [26]int

	for i := 0; i < len(s); i++ {
		letters[s[i]-'a']++
		letters[t[i]-'a']--
	}

	for _, value := range letters {
		if value != 0 {
			return false
		}
	}

	return true

}
