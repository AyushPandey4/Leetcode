class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int e1 = nums[0], e2 = nums[0];
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != e2){
                cnt1++;
                e1 = nums[i];
            } else if(cnt2 == 0 && nums[i] != e1){
                cnt2++;
                e2 = nums[i];
            } else if (nums[i] == e1) cnt1++;
            else if(nums[i] == e2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto it : nums){
            if(it == e1) cnt1++;
            else if(it == e2) cnt2++;
        }
        int cap = n/3 + 1;
        if(cnt1 >= cap) ans.push_back(e1);
        if(cnt2 >= cap && e1 != e2) ans.push_back(e2);
        return ans;
    }
};