class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int suff = 1, pre = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            pre *= nums[i];
            suff *= nums[n - i - 1];
            maxi = max(maxi, max(pre, suff));
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
        }
        return maxi;
    }
};