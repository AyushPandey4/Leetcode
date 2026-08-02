class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == nums.size() - 1)
            return nums[i];
        if (i > nums.size() - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + solve(i + 2, nums, dp),
                           0 + solve(i + 1, nums, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        vector<int> arr1, arr2;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0)
                arr1.push_back(nums[i]);
            if (i != nums.size() - 1)
                arr2.push_back(nums[i]);
        }
        return max(solve(0, arr1, dp1), solve(0, arr2, dp2));
    }
};