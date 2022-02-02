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
    vector<string> paths;
    void solve(string path, TreeNode *root) {
        path += "->" + to_string(root->val);

        if(root->left == NULL and root->right == NULL) {
            paths.push_back(path);
            return;
        }
        
        if(root->right != NULL)
            solve(path, root->right);
        if(root->left != NULL)
            solve(path, root->left);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        string path = to_string(root->val);
        if(root->left == NULL and root->right == NULL)
            return {path};
        if(root->left != NULL)
            solve(path, root->left);
        if(root->right != NULL)
            solve(path, root->right);
        
        return paths;
    }
};