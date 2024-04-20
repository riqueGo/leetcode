package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func diameterOfBinaryTree(root *TreeNode) int {
	maxDiameter := 0
	dfsDiameterOfBinaryTree(root, &maxDiameter)
	return maxDiameter
}

func dfsDiameterOfBinaryTree(root *TreeNode, maxDiameter *int) int {
	if root == nil {
		return 0
	}

	leftHeight := dfsDiameterOfBinaryTree(root.Left, maxDiameter)
	rightHeight := dfsDiameterOfBinaryTree(root.Right, maxDiameter)
	*maxDiameter = max(leftHeight+rightHeight, *maxDiameter)
	return max(leftHeight, rightHeight) + 1
}
