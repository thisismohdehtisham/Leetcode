class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // int ans = 0;
        // vector<int>indices(26);

        // for(int i=0; i<s.length(); i++){
        //     indices[s[i] - 'a'] = i;
        // }

        // for(int i=0; i<t.length(); i++){
        //     ans += abs(indices[t[i] - 'a'] - i); 
        // }
        // return ans;
        // TC -O(n), SC-O(1)

        unordered_map<char, int> map_s, map_t;

        for(int i=0; i<s.length(); i++){
            map_s[s[i]] = i;
            map_t[t[i]] = i;
        }
            
        int totalDiff = 0;
        for(auto pair : map_s){
            char ch = pair.first;
            totalDiff += abs(map_s[ch] - map_t[ch]);
        }

            return totalDiff;
            //TC - O(n), SC-O(n)
    }
};