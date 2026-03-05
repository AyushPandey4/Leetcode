class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        vector<int> pse = psel(arr);
        vector<int> nse = nser(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right * arr[i] % mod)) % mod;
        }
        return sum;
    }

private:
    vector<int> nser(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> psel(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
};