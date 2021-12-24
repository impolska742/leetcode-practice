/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool find(TreeNode *root, int data, vector<TreeNode*> &path) {
        if(root == NULL) return false;
        
        if(root->val == data) {
            path.push_back(root);
            return true;
        }
        
        bool l = find(root->left, data, path);
        if(l) {
            path.push_back(root);
            return true;
        }
        
        bool r = find(root->right, data, path);
        if(r) {
            path.push_back(root);
            return true;
        }
        
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        vector<TreeNode *> path1, path2;
        find(root, p->val, path1);
        find(root, q->val, path2);
        int i = path1.size() - 1, j = path2.size() - 1;
        while(i >= 0 and j >= 0 and path1[i]->val == path2[j]->val) {
            i--, j--;
        }
        return path1[i + 1];
    }
};