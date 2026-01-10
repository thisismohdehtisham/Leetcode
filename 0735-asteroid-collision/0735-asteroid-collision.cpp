class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop();
                    continue;
                } else if (st.top() == -ast) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push(ast);
            }
        }
        while (!st.empty()) {
            int val = st.top();
            ans.push_back(val);
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};