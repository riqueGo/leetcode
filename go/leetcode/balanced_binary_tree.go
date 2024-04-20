package leetcode

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type DepthBalancedSubTree struct {
	Height   int
	Balanced bool
}

func isBalanced(root *TreeNode) bool {
	return dfsTraverseTree(root).Balanced
}

func dfsTraverseTree(root *TreeNode) DepthBalancedSubTree {
	if root == nil {
		return DepthBalancedSubTree{0, true}
	}

	left, right := dfsTraverseTree(root.Left), dfsTraverseTree(root.Right)

	balanced := left.Balanced && right.Balanced && math.Abs(float64(left.Height-right.Height)) <= 1

	return DepthBalancedSubTree{Height: 1 + max(left.Height, right.Height), Balanced: balanced}
}
