class Solution {
private:
    TreeNode* prevNode = nullptr; 
    int min_diff = INT_MAX;

    void inOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);

        if (prevNode != nullptr) {
            min_diff = min(min_diff, node->val - prevNode->val);
        }
        prevNode = node; 

        inOrder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        prevNode = nullptr;
        min_diff = INT_MAX;
        
        inOrder(root);
        return min_diff;
    }
};