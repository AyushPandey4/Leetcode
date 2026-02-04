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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);

        vector<int> edge1, edge2;

        // Step 1: detect node with two parents
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                edge1 = {parent[v], v}; // earlier edge
                edge2 = e;              // later edge
                e[1] = 0;               // mark edge2 invalid
            }
        }

        // Step 2: DSU to detect cycle
        DSU ds(n + 1);
        for (auto& e : edges) {
            if (e[1] == 0)
                continue;

            int u = e[0], v = e[1];
            if (ds.find(u) == ds.find(v)) {
                // cycle detected
                if (edge1.empty())
                    return e; // case 1
                return edge1; // case 3
            }
            ds.unite(u, v);
        }

        // Step 3: no cycle
        return edge2; // case 2
    }
};