class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);

            while (!st.empty() && st.top()->val < num) {
                curr->left = st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.top()->right = curr;
            }

            st.push(curr);
        }

        while (st.size() > 1)
            st.pop();

        return st.top();
    }
};
