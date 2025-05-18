class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(),steps = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int median = nums[n/2];
            steps += abs(nums[i] - median); //The absolute value is always non-negative, abs() (or fabs(), std::abs()) always removes the negative sign.
        }
        return steps;
    }
};