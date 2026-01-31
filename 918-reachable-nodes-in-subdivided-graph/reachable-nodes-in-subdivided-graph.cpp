class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            adj[u].push_back({v, cnt + 1});
            adj[v].push_back({u, cnt + 1});
        }

        // Dijkstra
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;

        // Count original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                ans++;
        }

        // Count subdivided nodes
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];

            int a = dist[u] <= maxMoves ? maxMoves - dist[u] : 0;
            int b = dist[v] <= maxMoves ? maxMoves - dist[v] : 0;

            ans += min(cnt, a + b);
        }

        return ans;
    }
};
