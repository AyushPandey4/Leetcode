class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxi = 0;
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int nse = i;
                int el = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, (nse - pse -1) * arr[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top(); 
              maxi = max(maxi, (nse - pse -1) * arr[el]);
        }
        return maxi;
    }
};