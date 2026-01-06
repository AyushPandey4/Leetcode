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
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int x = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            int level = q.front().second;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
            if (sum > maxsum) {
                maxsum = sum;
                x = level;
            }
        }
        return x;
    }
};