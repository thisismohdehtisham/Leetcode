class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (auto c : s)
            freq[c - 'a']++;

        int max_consonant = 0, max_vowel = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                max_vowel = max(max_vowel, freq[i]);
            } else {
                max_consonant = max(max_consonant, freq[i]);
            }
        }
        return max_consonant + max_vowel;
    }
};