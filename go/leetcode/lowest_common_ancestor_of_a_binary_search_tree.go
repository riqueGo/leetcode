package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	for {
		if p.Val < root.Val && q.Val < root.Val {
			root = root.Left
		} else if p.Val > root.Val && q.Val > root.Val {
			root = root.Right
		} else {
			break
		}
	}
	return root
}

// func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
// 	pAncestors := getAncestors(root, p)
// 	qAncestors := getAncestors(root, q)

// 	i := 0
// 	for i < len(pAncestors) && i < len(qAncestors) && pAncestors[i] == qAncestors[i] {
// 		i++
// 	}
// 	return &pAncestors[i-1]
// }

// func getAncestors(root, targetNode *TreeNode) []TreeNode {
// 	var ancestors []TreeNode

// 	currentNode := root

// 	for currentNode != targetNode {
// 		ancestors = append(ancestors, *currentNode)

// 		if currentNode.Val < targetNode.Val {
// 			currentNode = currentNode.Right
// 		} else {
// 			currentNode = currentNode.Left
// 		}
// 	}

// 	ancestors = append(ancestors, *currentNode)
// 	return ancestors
// }
