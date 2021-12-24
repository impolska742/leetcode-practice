/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(root == NULL) return new TreeNode(data);
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        while(curr != NULL) {
            prev = curr;
            if(curr->val < data) curr = curr->right;
            else curr = curr->left;
        }
        curr = new TreeNode(data);
        if(prev->val < data) prev->right = curr;
        else prev->left = curr;
        return root;
    }
};