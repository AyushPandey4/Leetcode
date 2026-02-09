class Solution {
public:
    string ans = "~"; // larger than any lowercase string

    void dfs(TreeNode* root, string& path) {
        if (!root)
            return;

        // add current character
        path.push_back('a' + root->val);

        // if leaf, process
        if (!root->left && !root->right) {
            string curr = path;
            reverse(curr.begin(), curr.end());
            ans = min(ans, curr);
        }

        dfs(root->left, path);
        dfs(root->right, path);

        // backtrack
        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string path;
        dfs(root, path);
        return ans;
    }
};
