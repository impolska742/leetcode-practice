/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode find(TreeNode root, int x) {
        if(root == null) return null;
        if(root.val == x) return root;
        else if(x > root.val) return find(root.right, x);
        else return find(root.left, x);
    }
    public boolean targetSum(TreeNode root, TreeNode node, int sum) {
        if(node == null) return false;
        TreeNode temp = find(root, sum - node.val);
        if(temp != null && temp != node) return true;
        boolean l = targetSum(root, node.left, sum);
        if(l) return true;
        boolean r = targetSum(root, node.right, sum);
        if(r) return true;
        return false;
    }
    public boolean findTarget(TreeNode root, int k) {
        return targetSum(root, root, k);
    }
}