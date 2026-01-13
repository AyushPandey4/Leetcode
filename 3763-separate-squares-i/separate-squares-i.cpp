class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
      double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Precompute total area and y-range
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        // Binary search on y
        for (int iter = 0; iter < 80; iter++) {
            double mid = (low + high) / 2.0;
            double below = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                if (mid <= y) {
                    // contributes nothing
                } 
                else if (mid >= y + l) {
                    below += l * l;
                } 
                else {
                    below += (mid - y) * l;
                }
            }

            if (below < target)
                low = mid;     // line too low
            else
                high = mid;    // line too high
        }

        return low;

    }
};