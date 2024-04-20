package leetcode

import "strings"

func addBinary(a string, b string) string {
	if len(a) < len(b) {
		a = strings.Repeat("0", len(b)-len(a)) + a
	} else {
		b = strings.Repeat("0", len(a)-len(b)) + b
	}

	result := ""
	carry := false

	for i := len(a) - 1; i >= 0; i-- {

		if a[i] != b[i] {
			if carry {
				result = "0" + result
			} else {
				result = "1" + result
			}

		} else if a[i] == '0' {
			if carry {
				result = "1" + result
				carry = false
			} else {
				result = "0" + result
			}
		} else {
			if carry {
				result = "1" + result
			} else {
				result = "0" + result
			}
			carry = true
		}
	}

	if carry {
		return "1" + result
	}

	return result
}
