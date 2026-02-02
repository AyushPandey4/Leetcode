class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--;
        y--; // convert to 0-indexed

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // distance to self
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // path edges
        for (int i = 0; i < n - 1; i++) {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }

        // extra edge
        dist[x][y] = 1;
        dist[y][x] = 1;

        // Floyd–Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        vector<int> result(n, 0);

        // count ordered pairs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int d = dist[i][j];
                    if (d >= 1 && d <= n) {
                        result[d - 1]++;
                    }
                }
            }
        }

        return result;
    }
};
