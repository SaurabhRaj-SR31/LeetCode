class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize the answer vector with 0s
        stack<int> st; // Stack to keep track of indices of the temperatures
        
        for (int i = 0; i < n; ++i) {
            // While stack is not empty and current temperature is greater than temperature at index stored in stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                ans[index] = i - index; // Calculate the number of days
            }
            st.push(i); // Push the current index onto the stack
        }
        
        return ans;
    }
};