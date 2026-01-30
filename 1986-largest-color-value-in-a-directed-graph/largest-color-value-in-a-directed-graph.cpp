class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // dp[node][c] = max count of color c ending at node
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int processed = 0;
        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            int color = colors[node] - 'a';
            dp[node][color]++;
            ans = max(ans, dp[node][color]);

            for (int nei : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }

                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // If cycle exists
        if (processed != n)
            return -1;

        return ans;
    }
};
