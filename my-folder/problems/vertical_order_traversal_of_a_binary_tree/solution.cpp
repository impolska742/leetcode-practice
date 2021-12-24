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
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        
        return max(l, r) + 1;
    }
    
    static bool sortBy(const pair<int, int> &v1, const pair<int, int> &v2) {
        if(v1.first > v2.first) return true;
        else if(v2.first > v1.first) return false;
        else {
            return v1.second < v2.second;
        }
    }
    
    void dfs(TreeNode *root, int level, int height, map<int, vector<pair<int, int>>> &mp) {
        if(root == NULL) return;
        mp[level].push_back({height, root->val});
        dfs(root->left, level - 1, height-1, mp);
        dfs(root->right, level + 1, height-1,mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        int h = height(root);
        dfs(root, 0, h, mp);
        vector<vector<int>> ans;
        for(auto it : mp) {
            sort(it.second.begin(), it.second.end(), sortBy);
            vector<int> temp;
            for(auto x : it.second) {
                temp.push_back(x.second);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};