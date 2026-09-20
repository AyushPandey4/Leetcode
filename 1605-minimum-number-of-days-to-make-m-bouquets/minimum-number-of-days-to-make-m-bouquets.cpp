class Solution {
public:
    bool help(vector<int>& bloomDay, int m, int k, int days) {
        int curr = 0;
        int b = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                curr++;
                if (curr == k) {
                    b++;
                    curr = 0;
                }
            } else {
                curr = 0;
            }
        }
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long long)m * k)
            return -1;
        int l = 1, h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (help(bloomDay, m, k, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};