class Solution {
private:
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;
        TreeNode* rc = root->right;
        TreeNode* lr = findlastright(root->left);
        lr->right = rc;
        return root->left;
    }
    TreeNode* findlastright(TreeNode* root) {
        if (root->right == nullptr) {
            return root;
        }
        return findlastright(root->right);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
            return helper(root);
        TreeNode* curr = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return curr;
    }
};