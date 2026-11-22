class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            TreeNode* rightSide = nullptr;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node) {
                    rightSide = node;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            if (rightSide) {
                res.push_back(rightSide->val);
            }
        }

        return res;
        
    }
};