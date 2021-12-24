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
    class ITPair {
    public:
        int state;
        TreeNode *node;
        ITPair(TreeNode *root, int state) {
            this->node = root;
            this->state = state;
        }
    };

    TreeNode* getLeft(stack<ITPair> &ls) {
        while (!ls.empty()) {
            ITPair top = ls.top();
            ls.pop();
            // pre order
            if (top.state == 0) {
                top.state++;
                ls.push(top);
                if (top.node->left != NULL) {
                    ls.push(ITPair(top.node->left, 0));
                }
            }

            // in order
            else if (top.state == 1) {
                top.state++;
                ls.push(top);
                if (top.node->right != NULL) {
                    ls.push(ITPair(top.node->right, 0));
                }
                return top.node;
            }

            // post order
            else {
                // Nothing
            }
        }

        return NULL;
    }

    TreeNode* getRight(stack<ITPair> &rs) {
        while (!rs.empty()) {
            ITPair top = rs.top();
            rs.pop();

            // pre order
            if (top.state == 0) {
                top.state++;
                rs.push(top);
                if (top.node->right != NULL) {
                    rs.push(ITPair(top.node->right, 0));
                }
            }

            // in order
            else if (top.state == 1) {
                top.state++;
                rs.push(top);
                if (top.node->left != NULL) {
                    rs.push(ITPair(top.node->left, 0));
                }
                return top.node;
            }

            // post order
            else {
                // Nothing
            }
        }

        return NULL;
    }

    // using 2 stacks for inorder and reverse in-order
    bool findTarget(TreeNode* root, int sum) {
        stack<ITPair> ls;
        stack<ITPair> rs;

        ls.push(ITPair(root, 0));
        rs.push(ITPair(root, 0));

        TreeNode* left = getLeft(ls);
        TreeNode* right = getRight(rs);
        while (left->val < right->val) {
            int currSum = left->val + right->val;
            if (currSum == sum) {
                // cout << left->data << " " << right->data << endl;
                return true;
                left = getLeft(ls);
                right = getRight(rs);
            } else if (currSum > sum) {
                right = getRight(rs);
            } else {
                left = getLeft(ls);
            }
        }
        
        return false;
    }
};