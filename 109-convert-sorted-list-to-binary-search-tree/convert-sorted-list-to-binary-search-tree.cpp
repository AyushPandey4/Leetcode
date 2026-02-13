class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);

        // Find middle using slow-fast
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle
        if (prev) prev->next = NULL;  // cut left half

        TreeNode* root = new TreeNode(slow->val);

        // If head == slow, it means only one element
        if (head != slow)
            root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);

        return root;
    }
};
