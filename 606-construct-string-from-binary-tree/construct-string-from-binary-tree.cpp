class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root)
            return "";

        // leaf node
        if (!root->left && !root->right)
            return to_string(root->val);

        // only left child
        if (!root->right)
            return to_string(root->val) + "(" + tree2str(root->left) + ")";

        // has right child
        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" +
               tree2str(root->right) + ")";
    }
};
