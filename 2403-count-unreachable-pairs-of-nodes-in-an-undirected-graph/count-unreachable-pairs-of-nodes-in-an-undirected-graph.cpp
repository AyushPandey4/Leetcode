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

    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        // build components
        for (auto& e : edges) {
            dsu.unite(e[0], e[1]);
        }

        // count component sizes
        unordered_map<int, long long> compSize;
        for (int i = 0; i < n; i++) {
            compSize[dsu.find(i)]++;
        }

        long long ans = 0;
        long long remaining = n;

        for (auto& it : compSize) {
            long long s = it.second;
            remaining -= s;
            ans += s * remaining;
        }

        return ans;
    }
};
