class Solution {
public:
    bool help(vector<int>& bloomDay, int m, int k, int day) {
        int curr = 0, bou = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                curr++;
                if (curr == k) {
                    bou++;
                    curr = 0;
                }
            } else {
                curr = 0;
            }
        }
        return bou >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;
        int n = bloomDay.size();
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (help(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};