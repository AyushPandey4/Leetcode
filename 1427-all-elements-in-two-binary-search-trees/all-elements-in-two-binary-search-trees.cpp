class Solution {
public:
    void pushLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> result;

        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.empty() || !s2.empty()) {

            stack<TreeNode*>& st =
                s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)
                    ? s1
                    : s2;

            TreeNode* node = st.top();
            st.pop();

            result.push_back(node->val);
            pushLeft(node->right, st);
        }

        return result;
    }
};
