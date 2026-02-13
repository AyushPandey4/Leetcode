class Solution {
public:
    int sum = 0;
    void inorder(TreeNode* root, int low, int high) {
        if (!root)
            return;

        inorder(root->left, low, high);

        if (root->val >= low && root->val <= high)
            sum += root->val;

        inorder(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return sum;
    }
};