class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        long long ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + k - 1) / k;
            if (ans > h)
                return false;
        }
        return ans <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, hi = *max_element(piles.begin(), piles.end());
        int ans = 1;
        while (l <= hi) {
            int mid = l + (hi - l) / 2;
            if (check(piles, h, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};