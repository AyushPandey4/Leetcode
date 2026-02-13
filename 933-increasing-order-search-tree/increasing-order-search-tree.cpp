class Solution {
public:
    TreeNode* curr;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        // remove left child
        root->left = NULL;

        // attach to right of current
        curr->right = root;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        curr = dummy;

        inorder(root);

        return dummy->right;
    }
};
