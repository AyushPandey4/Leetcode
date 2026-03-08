class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        int cnt = 0;
        int minlen = INT_MAX;
        int si = -1;
        if (m < n)
            return "";
        vector<int> hash(256, 0);
        for (auto it : t)
            hash[it]++;
        int l = 0, r = 0;
        while (r < m) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            while (cnt == n) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    si = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return si == -1 ? "" : s.substr(si, minlen);
    }
};