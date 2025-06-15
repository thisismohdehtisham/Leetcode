class Solution {
private:
    bool ok(string a, string b){
        reverse(a.begin(), a.end());
        return (a == b);
};
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(ok(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};