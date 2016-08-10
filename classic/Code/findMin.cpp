class Solution {
public:
    int find(vector<int>& nums, int start, int end){
        if(end-start==2){
            return min(nums[start],nums[end-1]);
        }
        if(end-start==1){
            return nums[start];
        }
        int mid = (start+end)/2;
        if(nums[start]>=nums[end-1]){
            if (nums[mid-1]>nums[mid]){
                return nums[mid];
            }else{
                if(nums[mid]==nums[start]){
                    return min(find(nums,mid,end), find(nums,start,mid));
                }else if(nums[mid]>nums[start]){
                    return find(nums,mid,end);
                }else{
                    return find(nums,start,mid);
                }
            }
        }else{
            return nums[start];
        }
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        return find(nums, 0, nums.size());
        
    }
};
