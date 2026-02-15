class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == n)
            return;
        vector<int> temp(n, 0);
        int j = 0;
        for (int i = n - k; i < n; i++) {
            temp[j] = nums[i];
            j++;
        }
        for (int i = 0; i <= n - k - 1; i++) {
            temp[j] = nums[i];
            j++;
        }
        nums = temp;
    }
};