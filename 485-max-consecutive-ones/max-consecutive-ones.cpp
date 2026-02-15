class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                len++;
            else {
                maxi = max(maxi, len);
                len = 0;
            }
        }
        maxi = max(maxi, len);
        return maxi;
    }
};