class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int m = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int gap = 2; gap < m; gap++) {
            for (int l = 0; l + gap < m; l++) {
                int r = l + gap;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] +
                                                 nums[l] * nums[k] * nums[r]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
