class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            unordered_map<int, int> evenFreq, oddFreq;
            int evenCnt = 0, oddCnt = 0;

            for (int r = l; r < n; r++) {
                if (nums[r] % 2 == 0) {
                    if (++evenFreq[nums[r]] == 1)
                        evenCnt++;
                } else {
                    if (++oddFreq[nums[r]] == 1)
                        oddCnt++;
                }

                if (evenCnt == oddCnt) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};
