class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg = 0;
        int mini = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    neg++;
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if (neg % 2 == 1)
            return (sum - 2 * mini);
        return sum;
    }
};