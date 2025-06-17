class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char, int>mpp;

        int max_consonant = 0, max_vowel = 0;
        for(auto i : s){
            mpp[i]++;
            if(i == 'a' || i == 'e'|| i == 'i' || i == 'o' || i == 'u'){
                max_vowel = max(max_vowel, mpp[i]);
            }else{
                max_consonant = max(max_consonant, mpp[i]);
            }
        }
        return max_consonant + max_vowel;
    }
};