class Solution {
public:
    bool checkFreq(string & s){
        int arr[26] = {0};
        for(char &ch : s){
            arr[ch - 'a']++;
            if(arr[ch - 'a'] > 1)
                return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {

        // Brute-force but at large string size, it will TLE 
        // if(s.length() != goal.length()){
        //     return false;
        // }

        // vector<string>temp;
        // int n = s.size();

        // for(int i=0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         string k= s;
        //         swap(k[i], k[j]);
        //         temp.push_back(k);
        //     }
        // }

        // for(const string ch : temp){
        //     if(ch == goal)return true;
        // }
        // return false;

        // optimized approach

        if(s.length() != goal.length()){
            return false;
        }

        if(s == goal){
            return checkFreq(s);
        }

        vector<int>index;
        for(int i = 0; i< s.length(); i++){
            if(s[i] != goal[i]){
                index.push_back(i);
            }
        }
        if(index.size() != 2)
            return false;

        swap(s[index[0]], s[index[1]]);

        return s == goal;

    }
};