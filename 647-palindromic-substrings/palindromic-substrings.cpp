class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r]) {
                    if (len <= 2 || dp[l + 1][r - 1]) {
                        dp[l][r] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
