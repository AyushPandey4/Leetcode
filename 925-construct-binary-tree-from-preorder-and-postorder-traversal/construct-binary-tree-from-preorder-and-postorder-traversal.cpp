class Solution {
public:
    unordered_map<int, int> mp; // value -> index in postorder

    TreeNode* build(vector<int>& pre, int preStart, int preEnd,
                    vector<int>& post, int postStart, int postEnd) {

        if (preStart > preEnd)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preStart]);

        if (preStart == preEnd) // single node
            return root;

        int leftRootVal = pre[preStart + 1];
        int idx = mp[leftRootVal];

        int leftSize = idx - postStart + 1;

        root->left =
            build(pre, preStart + 1, preStart + leftSize, post, postStart, idx);

        root->right = build(pre, preStart + leftSize + 1, preEnd, post, idx + 1,
                            postEnd - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++)
            mp[postorder[i]] = i;

        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
