class Solution {
public:
    int maxArea(vector<int> &height) {
        int left=0;
        int right=height.size()-1;
        int maxVol=0;
        while (left<right){
            maxVol=max(maxVol,min(height[left],height[right])*(right-left));
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxVol;
    }
};
