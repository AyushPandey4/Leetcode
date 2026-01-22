class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: normalize each cuboid
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }

        // Step 2: sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int> dp(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; // height
            for (int j = 0; j < i; j++) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
