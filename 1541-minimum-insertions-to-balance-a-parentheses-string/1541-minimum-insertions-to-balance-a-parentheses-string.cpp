class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        stack<int>st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    if (i != s.length() - 1 && s[i + 1] == ')') {
                        cnt++;
                        i++;
                    } else {
                        cnt += 2;
                    }
                } else {
                    if (i != s.length() - 1 && s[i + 1] == ')') {
                        st.pop();
                        i++;
                    } else {
                        cnt++;
                        st.pop();
                    }
                }
            }
        }
        return cnt + st.size() * 2;
    }
};