class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        int n=0;
        for(int i=0;i<nums.size();i++){
            n=max(n,dp[i]);
        }
        return n;
    }
};
