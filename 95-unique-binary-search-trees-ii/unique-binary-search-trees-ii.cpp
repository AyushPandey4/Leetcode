/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int l, int r) {
        if (l > r)
            return {NULL};

        if (dp.count({l, r}))
            return dp[{l, r}];

        vector<TreeNode*> res;

        for (int i = l; i <= r; i++) {
            auto leftTrees = solve(l, i - 1);
            auto rightTrees = solve(i + 1, r);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return dp[{l, r}] = res;
    }

    vector<TreeNode*> generateTrees(int n) { return solve(1, n); }
};