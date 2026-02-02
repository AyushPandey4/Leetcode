class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (node == node2)
                return cost;

            if (cost > dist[node])
                continue;

            for (auto& [nei, wt] : adj[node]) {
                if (dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        return -1;
    }
};
