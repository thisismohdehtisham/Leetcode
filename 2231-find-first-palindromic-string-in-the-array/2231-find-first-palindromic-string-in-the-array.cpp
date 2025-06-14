class Solution {
private:
    bool checkPalindrome(string& s){
        int lp = 0;
        int rp = s.size()-1;

        while(lp < rp){
            if(s[lp] != s[rp])
                return false;
            lp++;
            rp--;
        }
        return true;
    };

public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (checkPalindrome(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};