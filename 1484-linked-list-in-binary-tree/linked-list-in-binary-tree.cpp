class Solution {
public:
    bool match(TreeNode* root, ListNode* head) {
        if (!head)
            return true;
        if (!root)
            return false;
        if (root->val != head->val)
            return false;

        return match(root->left, head->next) || match(root->right, head->next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;

        return match(root, head) || isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};
