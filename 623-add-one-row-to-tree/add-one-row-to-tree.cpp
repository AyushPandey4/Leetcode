/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            if (level == depth - 1) {
                // modify this level
                while (sz--) {
                    TreeNode* cur = q.front();
                    q.pop();

                    TreeNode* leftOld = cur->left;
                    TreeNode* rightOld = cur->right;

                    cur->left = new TreeNode(val);
                    cur->right = new TreeNode(val);

                    cur->left->left = leftOld;
                    cur->right->right = rightOld;
                }
                break; // important: stop BFS
            }

            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            level++;
        }

        return root;
    }
};