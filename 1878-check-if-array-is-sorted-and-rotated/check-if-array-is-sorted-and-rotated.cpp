class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int ind = -1;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1)
            return true;
        if (arr[n - 1] > arr[0])
            return false;
        for (int i = ind + 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};