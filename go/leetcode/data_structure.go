package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type ListNode struct {
	Val  int
	Next *ListNode
}

type StackNode struct {
	Val  int
	Next *StackNode
}

type Stack struct {
	Head *StackNode
}

func (s *Stack) IsEmpty() bool {
	return s.Head == nil
}

func (s *Stack) Push(val int) {
	node := StackNode{Val: val}

	if !s.IsEmpty() {
		node.Next = s.Head
	}

	s.Head = &node
}

func (s *Stack) Pop() int {
	temp := s.Head
	s.Head = s.Head.Next
	return temp.Val
}

func (s *Stack) Top() int {
	return s.Head.Val
}
