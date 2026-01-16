class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hGaps;
        unordered_set<int> vGaps;

        // All horizontal gaps
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        // All vertical gaps
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vGaps.insert(vFences[j] - vFences[i]);
            }
        }

        int maxSide = 0;

        for (int gap : hGaps) {
            if (vGaps.count(gap)) {
                maxSide = max(maxSide, gap);
            }
        }

        if (maxSide == 0) return -1;

        long long area = 1LL * maxSide * maxSide;
        return area % MOD;
    }
};
