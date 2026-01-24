class Solution {
public:
    int ans = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info dfs(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        Info cur;

        if (left.isBST && right.isBST && left.maxVal < root->val &&
            root->val < right.minVal) {

            cur.isBST = true;
            cur.sum = left.sum + right.sum + root->val;
            cur.minVal = min(left.minVal, root->val);
            cur.maxVal = max(right.maxVal, root->val);

            ans = max(ans, cur.sum);
        } else {
            cur.isBST = false;
        }

        return cur;
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
