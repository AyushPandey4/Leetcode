class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2, 0), ahead2(2, 0), cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            // buy allowed
            cur[1] = max(-prices[ind] + ahead[0], ahead[1]);

            // sell allowed (cooldown → ind + 2)
            cur[0] = max(prices[ind] + ahead2[1], ahead[0]);

            // shift states
            ahead2 = ahead;
            ahead = cur;
        }

        return ahead[1]; // dp[0][1]
    }
};