class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int top = 0, btm = n - 1, left = 0, right = m - 1;
        vector<int> ans;
        while (left <= right && top <= btm) {
            for (int i = left; i <= right; i++) {
                ans.push_back(mat[top][i]);
            }
            top++;
            for (int i = top; i <= btm; i++) {
                ans.push_back(mat[i][right]);
            }
            right--;
            if (top <= btm) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(mat[btm][i]);
                }
                btm--;
            }
            if (left <= right) {

                for (int i = btm; i >= top; i--) {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};