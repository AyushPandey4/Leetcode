class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Phase 1: Palindrome DP
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // Phase 2: Min cuts DP
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
