package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func middleNode(head *ListNode) *ListNode {
	faster := head

	for faster != nil && faster.Next != nil {
		head = head.Next
		faster = faster.Next.Next
	}
	return head
}
