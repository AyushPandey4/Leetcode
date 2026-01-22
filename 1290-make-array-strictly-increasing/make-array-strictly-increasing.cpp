class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        const int INF = 1e9;
        map<int, int> dp;
        dp[-1] = 0; // base: before first element, last value = -1

        for (int x : arr1) {
            map<int, int> new_dp;

            for (auto& [prev, cost] : dp) {
                // Option 1: keep arr1[i]
                if (x > prev) {
                    if (!new_dp.count(x) || new_dp[x] > cost)
                        new_dp[x] = cost;
                }

                // Option 2: replace with arr2 value
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int val = *it;
                    if (!new_dp.count(val) || new_dp[val] > cost + 1)
                        new_dp[val] = cost + 1;
                }
            }

            dp = move(new_dp);
            if (dp.empty())
                return -1;
        }

        int ans = INF;
        for (auto& [_, cost] : dp)
            ans = min(ans, cost);

        return ans;
    }
};
