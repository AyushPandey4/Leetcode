class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, string& s3,
               vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        int k = i + j - 1;
        bool ok = false;

        if (i > 0 && s1[i - 1] == s3[k])
            ok = ok || solve(i - 1, j, s1, s2, s3, dp);

        if (j > 0 && s2[j - 1] == s3[k])
            ok = ok || solve(i, j - 1, s1, s2, s3, dp);

        return dp[i][j] = ok;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, s1, s2, s3, dp);
    }
};
