class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int ms = INT_MIN, cs = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ms = max(ms, nums[i]);
            if(nums[i] <= 0 || seen.find(nums[i]) != seen.end()) continue;
            cs += nums[i];
            seen.insert(nums[i]);
        }
        return (ms <= 0) ? ms:cs;
    }
};