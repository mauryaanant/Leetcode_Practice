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
vector<int> modes;
    int current_val = 0;
    int current_count = 0;
    int max_count = 0;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (current_count == 0 || node->val == current_val) {
            current_val = node->val;
            current_count++;
        } else {
            current_val = node->val;
            current_count = 1;
        }

        if (current_count > max_count) {
            max_count = current_count;
            modes = {current_val};
        } else if (current_count == max_count) {
            modes.push_back(current_val);
        }

        inorder(node->right);
    }    

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};