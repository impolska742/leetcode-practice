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
private:
    int check(TreeNode *root, bool *ans) {
        if(root == NULL) return 0;
        int l = check(root->left, ans);
        int r = check(root->right, ans);
        
        *ans = *ans && (abs(l - r) <= 1);
        
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        check(root, &ans);
        return ans;
    }
};