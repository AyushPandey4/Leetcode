class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while ((long long)nums[l] * k < nums[r])
                l++;
            maxlen = max(maxlen, r - l + 1);
        }
        return n - maxlen;
    }
};