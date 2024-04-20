package leetcode

import datastructure "github.com/riqueGo/grind75/data-structure"

func IsValid(s string) bool {
	parenthesesMap := map[byte]byte{
		']': '[',
		'}': '{',
		')': '(',
	}

	if _, exists := parenthesesMap[s[0]]; exists {
		return false
	}

	var stack []byte

	for i := 0; i < len(s); i++ {
		if value, exists := parenthesesMap[s[i]]; exists {
			if len(stack) == 0 || value != stack[len(stack)-1] {
				return false
			} else {
				stack = stack[:len(stack)-1]
			}
		} else {
			stack = append(stack, s[i])
		}
	}
	return len(stack) == 0
}

func IsValidWithStackDS(s string) bool {
	parenthesesMap := map[byte]byte{
		']': '[',
		'}': '{',
		')': '(',
	}

	if _, exists := parenthesesMap[s[0]]; exists {
		return false
	}

	stack := datastructure.NewStack()

	for i := 0; i < len(s); i++ {
		if value, exists := parenthesesMap[s[i]]; exists {
			if stack.Lenght == 0 || value != stack.Peek().(byte) {
				return false
			} else {
				stack.Pop()
			}
		} else {
			stack.Push(s[i])
		}
	}
	return stack.Lenght == 0
}
