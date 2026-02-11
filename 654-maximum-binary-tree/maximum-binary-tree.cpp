class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int maxind = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] > nums[maxind]) {
                maxind = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxind]);
        root->left = build(nums, l, maxind - 1);
        root->right = build(nums, maxind + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};