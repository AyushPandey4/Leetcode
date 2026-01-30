class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> rev(n);

        // build indegree and reverse graph
        for (int i = 0; i < n; i++) {
            indeg[favorite[i]]++;
            rev[favorite[i]].push_back(i);
        }

        // remove non-cycle nodes (topological pruning)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        vector<int> depth(n, 0);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            int nxt = favorite[node];
            depth[nxt] = max(depth[nxt], depth[node] + 1);
            if (--indeg[nxt] == 0)
                q.push(nxt);
        }

        vector<bool> vis(n, false);
        int maxCycle = 0;
        int pairSum = 0;

        for (int i = 0; i < n; i++) {
            if (indeg[i] > 0 && !vis[i]) {
                int cur = i;
                int len = 0;

                // detect cycle
                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = favorite[cur];
                    len++;
                }

                if (len == 2) {
                    int a = i;
                    int b = favorite[i];
                    pairSum += 2 + depth[a] + depth[b];
                } else {
                    maxCycle = max(maxCycle, len);
                }
            }
        }

        return max(maxCycle, pairSum);
    }
};
