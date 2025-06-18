class Solution {
public:
    int minTimeToType(string word) {
        int n = word.length(), time = n;

        for(int i=1; i<n; i++){
            int move = abs(word[i-1] - word[i]);
            time += min(move, 26 - move);
        }
        return time + min(word[0] - 'a', 'z' - word[0] + 1);
    }
};