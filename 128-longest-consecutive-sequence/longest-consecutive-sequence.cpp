class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto it : nums)
            st.insert(it);
        int len = 0;
        for (auto x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                while (st.find(x + cnt) != st.end()) {
                    cnt++;
                }
                len = max(len, cnt);
            }
        }
        return len;
    }
};