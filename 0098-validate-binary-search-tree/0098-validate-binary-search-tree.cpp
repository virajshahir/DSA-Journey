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
    bool isBSTUtil(TreeNode* node, long long min, long long max) {
        if (node == nullptr) 
            return true;

        // If the current node's data 
        // is not in the valid range, return false
        if (node->val <= min || node->val >= max) 
            return false;

        // Recursively check the left and 
        // right subtrees with updated ranges
        return isBSTUtil(node->left, min, node->val) &&
               isBSTUtil(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        // Use long long limits to avoid overflow issues
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};