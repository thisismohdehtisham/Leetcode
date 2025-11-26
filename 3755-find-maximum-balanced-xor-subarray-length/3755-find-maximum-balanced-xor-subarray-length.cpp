class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        long long xorVal = 0;
        int balance = 0; // odd - even

        // map: xorVal -> (balance -> index)
        unordered_map<long long, unordered_map<int, int>> mp;

        // Base state (before starting): XOR=0, balance=0 at index -1
        mp[0][0] = -1;

        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            xorVal ^= nums[i];

            if (nums[i] % 2 == 0)
                balance--; // even
            else
                balance++; // odd

            // If same (xor, balance) seen before → valid subarray
            if (mp[xorVal].count(balance)) {
                int startIndex = mp[xorVal][balance];
                maxLen = max(maxLen, i - startIndex);
            } else {
                mp[xorVal][balance] = i; // store first occurrence
            }
        }

        return maxLen;
    }
};