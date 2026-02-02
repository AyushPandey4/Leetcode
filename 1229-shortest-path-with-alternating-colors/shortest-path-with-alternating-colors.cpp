class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<vector<int>> redAdj(n), blueAdj(n);

        for (auto& e : redEdges)
            redAdj[e[0]].push_back(e[1]);

        for (auto& e : blueEdges)
            blueAdj[e[0]].push_back(e[1]);

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> ans(n, -1);

        queue<pair<int, int>> q;
        // color: 0 = red, 1 = blue

        q.push({0, 0});
        q.push({0, 1});
        visited[0][0] = visited[0][1] = true;

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, lastColor] = q.front();
                q.pop();

                if (ans[node] == -1)
                    ans[node] = dist;

                // If last edge was red → take blue next
                if (lastColor == 0) {
                    for (int nei : blueAdj[node]) {
                        if (!visited[nei][1]) {
                            visited[nei][1] = true;
                            q.push({nei, 1});
                        }
                    }
                }
                // If last edge was blue → take red next
                else {
                    for (int nei : redAdj[node]) {
                        if (!visited[nei][0]) {
                            visited[nei][0] = true;
                            q.push({nei, 0});
                        }
                    }
                }
            }
            dist++;
        }

        return ans;
    }
};
