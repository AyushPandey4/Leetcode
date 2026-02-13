class Solution {
public:
    ListNode* curr;

    int getSize(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    TreeNode* build(int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;

        // Build left subtree
        TreeNode* leftChild = build(left, mid - 1);

        // Current node becomes root
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        // Attach left
        root->left = leftChild;

        // Build right subtree
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getSize(head);
        curr = head;
        return build(0, n - 1);
    }
};
