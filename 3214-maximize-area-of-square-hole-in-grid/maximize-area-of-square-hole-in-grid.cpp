class Solution {
public:
    int maxgap(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int curr = 1, longest = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            longest = max(curr, longest);
        }
        return longest;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int maxh = maxgap(hBars) + 1;
        int maxv = maxgap(vBars) + 1;
        int side = min(maxh, maxv);
        return side * side;
    }
};