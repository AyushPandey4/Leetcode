class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, curr = -1;
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                curr = nums[i];
            }
            if (curr == nums[i])
                cnt++;
            else
                cnt--;
        }
        return curr;
    }
};