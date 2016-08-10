/*OPT(n) = max(value[n] + OPT(n - 2), OPT(n-1))*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size(),0);
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=max(nums[nums.size()-1],nums[nums.size()-2]);
        for(int i=nums.size()-3;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
