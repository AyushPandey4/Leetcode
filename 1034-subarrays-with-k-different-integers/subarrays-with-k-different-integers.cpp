class Solution {
public:
    int help(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};