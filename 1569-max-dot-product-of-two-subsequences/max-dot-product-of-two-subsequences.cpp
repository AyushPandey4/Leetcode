class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, INT_MIN));
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j] + max(0, dp[i + 1][j + 1]);
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];
                dp[i][j] = max(max(skip1, skip2), take);
            }
        }
        return dp[0][0];
    }
};