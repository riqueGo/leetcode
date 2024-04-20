package DataStructures;

import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    public TreeNode left;
    public TreeNode right;
    public int value;

    public TreeNode(int value) {
        this.value = value;
        this.right = null;
        this.left = null;
    }
}

public class Tree {
    public TreeNode root;

    public Tree(TreeNode root) {
        this.root = root;
    }

    public Tree(){}

    public static void main(String[] args) {
        Tree tree = new Tree(new TreeNode(5));
        tree.insert(1);
        tree.insert(9);
        tree.insert(2);
        tree.insert(7);
        tree.insert(3);
        tree.insert(6);
        tree.insert(4);
        tree.insert(8);

        tree.traverseInOrder(tree.root);
        System.out.println();
        tree.traversePreOrder(tree.root);
        System.out.println();
        tree.traversePosOrder(tree.root);
        System.out.println();
        tree.traverseLevelOrder();
    }

    public void insert(int value) {
        root = insertRecursive(root, value);
    }

    private TreeNode insertRecursive(TreeNode currentNode, int value) {
        if (currentNode == null) {
            return new TreeNode(value);
        }

        if (value < currentNode.value) {
            currentNode.left = insertRecursive(currentNode.left, value);
        } else if (value > currentNode.value) {
            currentNode.right = insertRecursive(currentNode.right, value);
        }
        
        return currentNode;
    }

    public void display() {
        displayRecursive(root);
    }

    private void displayRecursive(TreeNode currentNode) {
        if (currentNode != null) {
            displayRecursive(currentNode.left);
            System.out.println(currentNode.value);
            displayRecursive(currentNode.right);
        }
    }

    public boolean containsNode(int value) {
        return containsNodeRecursive(root, value);
    }

    private boolean containsNodeRecursive(TreeNode currentNode, int value) {
        if (currentNode == null) {
            return false;
        }

        if (currentNode.value == value) {
            return true;
        }

        return currentNode.value > value ?
            containsNodeRecursive(currentNode.left, value) :
            containsNodeRecursive(currentNode.right, value);
    }

    public void delete(int value) {
        root = deleteRecursive(root, value);
    }

    private TreeNode deleteRecursive(TreeNode currentNode, int value) {
        if (currentNode == null) {
            return null;
        }

        if (value < currentNode.value) {
            currentNode.left = deleteRecursive(currentNode.left, value);
        } else if (value > currentNode.value) {
            currentNode.right = deleteRecursive(currentNode.right, value);
        } else {
            if (currentNode.left == null && currentNode.right == null) {
                currentNode = null;
            } else if (currentNode.right != null) {
                currentNode.value = sucessor(currentNode);
                currentNode.right = deleteRecursive(currentNode.right, currentNode.value);
            } else {
                currentNode.value = predecessor(currentNode);
                currentNode.left = deleteRecursive(currentNode.left, currentNode.value);
            }
        }
        return currentNode;
    }

    private int sucessor(TreeNode currentNode){
        return findSmallestValue(currentNode.right);
    }

    private int predecessor(TreeNode currentNode){
        return findGreatestValue(currentNode.left);
    }

    public int findSmallestValue(TreeNode currentNode) {
        return currentNode.left == null ? currentNode.value : findSmallestValue(currentNode.left);
    }

    public int findGreatestValue(TreeNode currentNode) {
        return currentNode.right == null ? currentNode.value : findSmallestValue(currentNode.right);
    }

    public void traverseInOrder(TreeNode currentNode){
        if (currentNode!=null) {
            traverseInOrder(currentNode.left);
            System.out.print(" " + currentNode.value);
            traverseInOrder(currentNode.right);
        }
    }

    public void traversePreOrder(TreeNode currentNode){
        if (currentNode!=null) {
            System.out.print(" " + currentNode.value);
            traversePreOrder(currentNode.left);
            traversePreOrder(currentNode.right);
        }
    }

    public void traversePosOrder(TreeNode currentNode){
        if (currentNode!=null) {
            traversePosOrder(currentNode.left);
            traversePosOrder(currentNode.right);
            System.out.print(" " + currentNode.value);
        }
    }

    public void traverseLevelOrder() {
        if (root==null) {
            return;
        }

        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.add(root);

        while (!nodes.isEmpty()) {
            TreeNode node = nodes.remove();
            System.out.print(" " + node.value);

            if (node.left != null) {
                nodes.add(node.left);
            }

            if (node.right != null) {
                nodes.add(node.right);
            }
        }
    }

}
