class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        if(n % k != 0) return false;

        int groups = n / k;
        unordered_map<int, int> freq;
        for (int num : temp) {
            freq[num]++;
            if (freq[num] > groups) {
                return false; // Too many occurrences of a number
            }
        }
        return true;
    }
};