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
    bool equationsPossible(vector<string>& equations) {
        DSU ds(26);

        // Step 1: process all ==
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                ds.unite(u, v);
            }
        }

        // Step 2: process all !=
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                if (ds.find(u) == ds.find(v)) {
                    return false;
                }
            }
        }

        return true;
    }
};