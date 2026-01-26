class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mindiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            mindiff = min(mindiff, diff);
        }
        for (int i = 1; i < n; i++) {
            if (mindiff == (arr[i] - arr[i - 1])) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};