class Solution {
public:
    int solve(int ind, int z, int o, vector<pair<int, int>>& cnt,
              vector<vector<vector<int>>>& dp) {

        // Base case: no strings left
        if (ind < 0)
            return 0;

        if (dp[ind][z][o] != -1)
            return dp[ind][z][o];

        // Not take
        int notTake = solve(ind - 1, z, o, cnt, dp);

        // Take (if possible)
        int take = 0;
        if (cnt[ind].first <= z && cnt[ind].second <= o) {
            take = 1 + solve(ind - 1, z - cnt[ind].first, o - cnt[ind].second,
                             cnt, dp);
        }

        return dp[ind][z][o] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // int k = strs.size();
        // vector<pair<int, int>> cnt(k);

        // for (int i = 0; i < k; i++) {
        //     int z = 0, o = 0;
        //     for (char c : strs[i]) {
        //         if (c == '0')
        //             z++;
        //         else
        //             o++;
        //     }
        //     cnt[i] = {z, o};
        // }
        // vector<vector<vector<int>>> dp(
        //     k, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // return solve(k - 1, m, n, cnt, dp);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string& s : strs) {

            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }

            // 0/1 knapsack → backward loops
            for (int z = m; z >= zeros; z--) {
                for (int o = n; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o], 1 + dp[z - zeros][o - ones]);
                }
            }
        }

        return dp[m][n];
    }
};