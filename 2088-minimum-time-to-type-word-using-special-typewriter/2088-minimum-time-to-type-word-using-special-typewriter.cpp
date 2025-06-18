class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.size(), point = 'a';
        for(auto ch : word){
            ans += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return ans;
    }
};