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
    int max(TreeNode *root) {
        if(root == NULL) return INT_MIN;
        if(root->right != NULL) return max(root->right);
        else return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return root;
        
        if(val > root->val)
            root->right = deleteNode(root->right, val);
        else if(val < root->val)
            root->left = deleteNode(root->left, val);
        else {
            // 2 Child
            if(root->left != NULL and root->right != NULL) {
                int lMax = max(root->left);
                root->val = lMax;
                root->left = deleteNode(root->left, lMax);
                return root;
            }
            
            // 1 Child :: Left
            else if(root->left != NULL) {
                return root->left;
            }
            
            // 1 Child :: Right
            else if(root->right != NULL) {
                return root->right;
            }
            
            // 0 Child
            else {
                return NULL;
            }
        }
        
        return root;
    }
};