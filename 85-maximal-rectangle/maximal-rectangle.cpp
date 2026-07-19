class Solution {
private:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int nse = i;
                int el = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, arr[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, arr[el] * (nse - pse - 1));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Update the heights for the current row dynamically
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            // Run the stack algorithm directly on the updated 1D heights
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};