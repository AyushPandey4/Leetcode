class Solution {
public:
    int solve(int i, vector<int>& dp) {
        if (i == 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = i; // worst case: copy 1, paste (i-1) times

        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                ans = min(ans, solve(j, dp) + (i / j));
            }
        }

        return dp[i] = ans;
    }

    int minSteps(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};