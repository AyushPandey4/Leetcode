class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long total = 0;
    long long ans = 0;

    long long getTotal(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root)
            return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        ans = max(ans, subSum * (total - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        total = getTotal(root);
        dfs(root);
        return ans % MOD;
    }
};
