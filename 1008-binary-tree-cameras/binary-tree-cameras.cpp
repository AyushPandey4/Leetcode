class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (!root)
            return 2; // null nodes are considered covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Rule 1
        if (left == 0 || right == 0) {
            cameras++;
            return 1; // has camera
        }

        // Rule 2
        if (left == 1 || right == 1) {
            return 2; // covered
        }

        // Rule 3
        return 0; // not covered
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0)
            cameras++;
        return cameras;
    }
};
