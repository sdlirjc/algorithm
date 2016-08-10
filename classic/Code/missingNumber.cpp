class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tmp=0;
        for(int n:nums){
            tmp^=n;
        }
        for(int i=0;i<=nums.size();i++){
            tmp^=i;
        }
        return tmp;
    }
};
