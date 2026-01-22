class Solution {
public:
    struct Node {
        long long val;
        int prev, next;
        bool alive;
    };

    bool isSorted(vector<Node>& nodes, int head) {
        int cur = head;
        while (nodes[cur].next != -1) {
            int nxt = nodes[cur].next;
            if (nodes[nxt].val < nodes[cur].val) return false;
            cur = nxt;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<Node> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = {nums[i], i - 1, i + 1, true};
        }
        nodes[0].prev = -1;
        nodes[n - 1].next = -1;

        int head = 0;

        // min heap: (sum, left_index)
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({nodes[i].val + nodes[i + 1].val, i});
        }

        int ops = 0;

        while (!isSorted(nodes, head)) {
            auto [sum, i] = pq.top();
            pq.pop();

            // invalid pair check
            if (!nodes[i].alive) continue;
            int j = nodes[i].next;
            if (j == -1 || !nodes[j].alive) continue;
            if (nodes[i].val + nodes[j].val != sum) continue;

            // merge i and j
            nodes[i].val = sum;
            nodes[j].alive = false;

            int r = nodes[j].next;
            nodes[i].next = r;
            if (r != -1) nodes[r].prev = i;

            ops++;

            // push new adjacent pairs
            if (nodes[i].prev != -1) {
                int l = nodes[i].prev;
                pq.push({nodes[l].val + nodes[i].val, l});
            }
            if (nodes[i].next != -1) {
                pq.push({nodes[i].val + nodes[nodes[i].next].val, i});
            }
        }

        return ops;
    }
};
