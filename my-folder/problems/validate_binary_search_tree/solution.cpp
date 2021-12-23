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
    struct bst{
        long long int min, max;
        bool isBST = false;
    };
    
    bst isTreeBST(TreeNode *root) {
        if(root == NULL) {
            bst base;
            base.min = (long long int) INT_MAX * 2000;
            base.max = (long long int) INT_MIN * 2000;
            base.isBST = true;
            return base;
        }
        
        bst l = isTreeBST(root->left);
        bst r = isTreeBST(root->right);
        
        bst ans;
        ans.min = min({(long long int) root->val, l.min, r.min});
        ans.max = max({(long long int) root->val, l.max, r.max});
        ans.isBST = l.isBST and r.isBST and (l.max < root->val and r.min > root->val);
        return ans;         
    }    
public:
    bool isValidBST(TreeNode* root) {
        return isTreeBST(root).isBST; 
    }
};