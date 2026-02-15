class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1;
        while (r < n) {
            if (nums[r] != nums[l]) {
                l++;
                swap(nums[l], nums[r]);
            }
            r++;
        }
        return l + 1;
    }
};