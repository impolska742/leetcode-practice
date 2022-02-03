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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) 
            return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int temp_size = Q.size();
            vector<int> level;
            
            for(int i = 0; i < temp_size; i++) {
                TreeNode *top = Q.front();
                Q.pop();
                level.push_back(top->val);
                
                if(top->left != NULL)
                    Q.push(top->left);
                if(top->right != NULL)
                    Q.push(top->right);
            }
            
            result.push_back(level);
        }
        return result;
    }
};