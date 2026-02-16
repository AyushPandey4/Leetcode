class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posind = 0 , negind = 1;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posind] = nums[i];
                posind += 2;
            }else{
                ans[negind] = nums[i];
                negind += 2;
            }
        }
        return ans;
    }
};