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
    public static int max(TreeNode root) {
        if(root == null) return Integer.MIN_VALUE;
        if(root.right != null) return max(root.right);
        else return root.val;
    }

    public TreeNode deleteNode(TreeNode root, int val) {
        if(root == null) return root;
        
        if(val > root.val)
            root.right = deleteNode(root.right, val);
        else if(val < root.val)
            root.left = deleteNode(root.left, val);
        else {
            // 2 Child
            if(root.left != null && root.right != null) {
                int lMax = max(root.left);
                root.val = lMax;
                root.left = deleteNode(root.left, lMax);
                return root;
            }
            
            // 1 Child :: Left
            else if(root.left != null) {
                return root.left;
            }
            
            // 1 Child :: Right
            else if(root.right != null) {
                return root.right;
            }
            
            // 0 Child
            else {
                return null;
            }
        }
        
        return root;
    }
}