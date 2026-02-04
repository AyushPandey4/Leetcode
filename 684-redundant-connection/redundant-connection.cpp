struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n + 1); // nodes are 1-based

        vector<int> ans;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (ds.find(u) == ds.find(v)) {
                ans = e; // cycle-causing edge
            } else {
                ds.unite(u, v);
            }
        }
        return ans;
    }
};