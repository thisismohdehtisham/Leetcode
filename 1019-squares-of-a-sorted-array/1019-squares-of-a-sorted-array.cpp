class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        // for(int i = 0; i<n; i++){
        //     int square = abs(nums[i])*abs(nums[i]);
        //     ans.push_back(square);
        // }
        // sort(ans.begin(), ans.end());
        // return ans; 
        // TC- O(nlogn), SC-O(n)

        int i=0, j=n-1;
        int k = n-1;

        while(k >= 0){
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a>b){
                ans[k] = a;
                i++;
            }else{
                ans[k] = b;
                j--;
            }
            k--;
        }
        return ans;
    }
};