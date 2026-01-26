class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string curr, string target, unordered_set<string>& vis) {
        if (curr == target)
            return 1.0;

        vis.insert(curr);

        for (auto& [next, val] : graph[curr]) {
            if (vis.count(next))
                continue;

            double res = dfs(next, target, vis);
            if (res != -1.0) {
                return val * res;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string C = q[0];
            string D = q[1];

            if (!graph.count(C) || !graph.count(D)) {
                ans.push_back(-1.0);
            } else {
                unordered_set<string> vis;
                ans.push_back(dfs(C, D, vis));
            }
        }
        return ans;
    }
};
