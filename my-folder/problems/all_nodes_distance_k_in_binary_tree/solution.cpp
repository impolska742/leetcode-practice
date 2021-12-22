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
public:
    vector<int> ans;
    // 2. O(N) - Efficient
    void printKLevelsDown(TreeNode *root, int k, TreeNode* blockader, int depth = 0) {
        if (root == NULL or depth > k or root == blockader) return;
        if (depth == k) ans.push_back(root->val);

        printKLevelsDown(root->left, k, blockader, depth + 1);
        printKLevelsDown(root->right, k, blockader, depth + 1);
    }

    // For calculating the node to root path
    vector<TreeNode*> path;
    bool find(TreeNode *node, int x) {
        if (node == NULL) return false;
        if (node->val == x) {
            path.push_back(node);
            return true;
        }

        bool leftAns = find(node->left, x);
        if (leftAns) {
            path.push_back(node);
            return true;
        }

        bool rightAns = find(node->right, x);
        if (rightAns) {
            path.push_back(node);
            return true;
        }

        return false;
    }

    void printKDistanceAway2(TreeNode *root, int d, int k) {
        find(root, d);
        for (int i = 0; i < path.size(); i++) {
            TreeNode *blockader = NULL;
            if (i >= 1) blockader = path[i - 1];
            printKLevelsDown(path[i], k - i, blockader);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        printKDistanceAway2(root, target->val, k);
        return ans;
    }
};