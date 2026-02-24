class Solution {
public:
    bool help(vector<int>& nums, int k, int checkSum) {
        int split = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > checkSum) {
                split++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (help(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};