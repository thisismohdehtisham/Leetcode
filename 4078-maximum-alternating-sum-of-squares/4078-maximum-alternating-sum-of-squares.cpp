class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0) nums[i] *= -1;
        }

        sort(nums.begin(), nums.end());
        long long ans = 0;

        for(int i=0; i<nums.size(); i++){
            if(i<nums.size()/2){
                ans -= (nums[i]*nums[i]);
            }else{
                ans += (nums[i]*nums[i]);
            }
        }
        return ans;
    }
};