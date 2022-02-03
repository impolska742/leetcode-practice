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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> traverse = new ArrayList<Integer>();
        help(traverse, root);
        return traverse;
    }
    
    public void help(List<Integer> traverse, TreeNode root) {
        if(root == null)
            return;
        traverse.add(root.val);
        help(traverse, root.left);
        help(traverse, root.right);
    }
}