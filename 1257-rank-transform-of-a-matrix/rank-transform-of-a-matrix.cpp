class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        vector<tuple<int, int, int>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({matrix[i][j], i, j});

        sort(cells.begin(), cells.end());

        vector<int> rowRank(m, 0), colRank(n, 0);

        int i = 0;
        while (i < cells.size()) {
            int j = i;
            while (j < cells.size() && get<0>(cells[j]) == get<0>(cells[i]))
                j++;

            unordered_map<int, int> rowMap, colMap;

            for (int k = i; k < j; k++) {
                int r = get<1>(cells[k]);
                int c = get<2>(cells[k]);
                if (!rowMap.count(r))
                    rowMap[r] = rowMap.size();
                if (!colMap.count(c))
                    colMap[c] = colMap.size();
            }

            int R = rowMap.size();
            int C = colMap.size();

            DSU dsu(R + C);

            for (int k = i; k < j; k++) {
                int r = get<1>(cells[k]);
                int c = get<2>(cells[k]);
                int rowNode = rowMap[r];
                int colNode = colMap[c] + R;
                dsu.unite(rowNode, colNode);
            }

            unordered_map<int, int> compMax;
            for (int k = i; k < j; k++) {
                int r = get<1>(cells[k]);
                int c = get<2>(cells[k]);
                int root = dsu.find(rowMap[r]);
                compMax[root] = max(compMax[root], max(rowRank[r], colRank[c]));
            }

            for (int k = i; k < j; k++) {
                int r = get<1>(cells[k]);
                int c = get<2>(cells[k]);
                int root = dsu.find(rowMap[r]);
                ans[r][c] = compMax[root] + 1;
            }

            for (int k = i; k < j; k++) {
                int r = get<1>(cells[k]);
                int c = get<2>(cells[k]);
                rowRank[r] = max(rowRank[r], ans[r][c]);
                colRank[c] = max(colRank[c], ans[r][c]);
            }

            i = j;
        }

        return ans;
    }
};
