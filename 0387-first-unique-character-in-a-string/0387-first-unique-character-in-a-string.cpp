class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>mpp;

        for(char i : s){
            mpp[i]++;
        }

        for(int x=0; x<s.size(); x++){
            if(mpp[s[x]] == 1){
                return x;
            }
        }
        return -1;
    }
};