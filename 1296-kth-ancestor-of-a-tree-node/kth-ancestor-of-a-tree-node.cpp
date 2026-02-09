class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20; // enough for n <= 2e5
        up.assign(n, vector<int>(LOG, -1));

        // 2^0 ancestor (direct parent)
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // build table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1)
                    up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
