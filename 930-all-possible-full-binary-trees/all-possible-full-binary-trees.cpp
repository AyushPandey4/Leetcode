class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.count(n))
            return memo[n];

        vector<TreeNode*> res;

        if (n == 1) {
            res.push_back(new TreeNode(0));
            return memo[n] = res;
        }

        if (n % 2 == 0)
            return res; // empty

        for (int i = 1; i < n; i += 2) {
            auto leftTrees = allPossibleFBT(i);
            auto rightTrees = allPossibleFBT(n - 1 - i);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return memo[n] = res;
    }
};
