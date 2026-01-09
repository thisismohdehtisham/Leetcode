class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                st.pop();
                int new_val = 0;
                if (c == "+") {
                    new_val = prev2 + prev1;
                } else if (c == "-") {
                    new_val = prev2 - prev1;
                } else if (c == "*") {
                    new_val = prev2 * prev1;
                } else {
                    new_val = prev2 / prev1;
                }
                st.push(new_val);
            } else {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};