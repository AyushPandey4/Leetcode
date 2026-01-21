class Solution {
public:
    bool isAllStars(string& p, int j) {
        for (int k = 0; k < j; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        int n = s.length(); // string
        int m = p.length(); // pattern

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // empty string vs pattern
        for (int j = 1; j <= m; j++) {
            dp[0][j] = isAllStars(p, j);
        }

        // string vs empty pattern already false by default

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || // '*' matches empty
                               dp[i - 1][j];   // '*' matches one char
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
