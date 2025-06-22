class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        // int n = s.length(), m = target.length();
        // int count = 0, bigCount = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(s[i] == target[j]){
        //             count++;
        //             i++;
        //         }
        //     }
        //     if(count == m){
        //         bigCount += 1;
        //         count = 0;
        //     }
        // }
        // return bigCount;

        vector<int>v(26,0);
        for(char ch : s){
            v[ch - 'a']++; //storing the 0-base indexing using the deduction of ASCII indexing
        }
            int counter =0;
            while(true){
                for(char ch : target){
                    if(v[ch - 'a'] == 0) return counter;
                    v[ch - 'a']--;
                }
                counter++;
            }
            return counter;
        
    }
};