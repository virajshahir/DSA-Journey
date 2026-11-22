class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int minLevel = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left == nullptr && node->right == nullptr)
                    return minLevel;

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }

            minLevel++;
        }

        return minLevel;
    }
};