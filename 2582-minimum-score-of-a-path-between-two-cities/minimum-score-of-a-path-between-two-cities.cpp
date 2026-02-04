class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> vis(n + 1, false);
        int ans = INT_MAX;

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto& [v, w] : g[u]) {
                ans = min(ans, w);
                if (!vis[v])
                    dfs(v);
            }
        };

        dfs(1);
        return ans;
    }
};