class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> pre(n + 1, 0), suff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (s[i] == 'b');
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + (s[i] == 'a');
        }
        int ans = n;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, pre[i] + suff[i]);
        }
        return ans;
    }
};