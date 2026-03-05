class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        for (int i = 0; i < nums.length(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (nums[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while (ans.size() != 0 && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        if (ans.empty())
            return "0";
        return ans;
    }
};