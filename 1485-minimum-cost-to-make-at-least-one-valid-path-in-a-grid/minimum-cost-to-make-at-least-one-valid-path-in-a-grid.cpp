class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> dist(m, vector<int>(n, INF));
        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        // right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                // grid value: 1=right,2=left,3=down,4=up
                int cost = (grid[x][y] == dir + 1) ? 0 : 1;

                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
