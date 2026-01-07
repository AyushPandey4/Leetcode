class Solution {
public:
    long long totalSum = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* node) {
        if (!node)
            return 0;

        long long left = dfs(node->left);
        long long right = dfs(node->right);

        long long subTreeSum = left + right + node->val;

        best = max(best, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        dfsSum(root);

        dfs(root);

        return best % MOD;
    }

private:
    long long dfsSum(TreeNode* node) {
        if (!node)
            return 0;
        totalSum += node->val;
        dfsSum(node->left);
        dfsSum(node->right);
        return totalSum;
    }
};
