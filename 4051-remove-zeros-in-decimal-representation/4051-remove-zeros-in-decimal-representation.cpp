class Solution {
public:
    long long removeZeros(long long n) {
        string nn = to_string(n);
        string ans = "";

        for(char c : nn){
            if(c != '0'){
                ans += c;
            }
        }
        long long res = stoll(ans);

        return res;
    }
};