class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftZig = 0, rightZig = 0;

        if (root->left)
            leftZig = 1 + left.second; // came from right before

        if (root->right)
            rightZig = 1 + right.first; // came from left before

        ans = max(ans, max(leftZig, rightZig));

        return {leftZig, rightZig};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
