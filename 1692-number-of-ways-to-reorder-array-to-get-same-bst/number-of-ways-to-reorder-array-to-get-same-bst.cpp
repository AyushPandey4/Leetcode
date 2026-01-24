class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    pair<int, long long> dfs(vector<int>& nums) {
        if (nums.empty())
            return {0, 1};

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        auto [lSize, lWays] = dfs(left);
        auto [rSize, rWays] = dfs(right);

        long long ways = nCr(lSize + rSize, lSize);
        ways = ways * lWays % MOD;
        ways = ways * rWays % MOD;

        return {lSize + rSize + 1, ways};
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        return (dfs(nums).second - 1 + MOD) % MOD; // exclude original ordering
    }
};
