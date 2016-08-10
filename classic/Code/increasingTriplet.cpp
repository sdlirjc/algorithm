class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1=0x7fffffff;
        int x2=0x7fffffff;
        for (int i=0;i<nums.size();i++){
            if(nums[i]<=x1){
                x1=nums[i];
            }else if(nums[i]<=x2){
                x2=nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
};
