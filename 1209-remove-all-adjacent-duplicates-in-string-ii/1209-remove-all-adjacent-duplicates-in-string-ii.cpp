class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;

        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
            } else {
                stack.push_back({c, 1});
            }
            if (stack.back().second == k) {
                stack.pop_back();
            }
        }

        string res;
        for (auto& p : stack) {
            // string& append(size_t count, char ch);
            // p = {'a', 3}
            // res.append(3, 'a'), res = "aaa"
            res.append(p.second, p.first);  
        }

        return res;
    }
};